//Black Shapes

void dfs(int i, int j, vector <vector <int> > &visited, vector <string> &A) {
    int n = visited.size();
    int m = visited[0].size();
    visited[i][j] = 1;
    if (i + 1 < n && (! visited[i + 1][j]) && A[i + 1][j] == 'X') {
        dfs(i + 1, j, visited, A);
    }
    if (j + 1 < m && (! visited[i][j + 1]) && A[i][j + 1] == 'X') {
        dfs(i, j + 1, visited, A);
    }
    if (i - 1 >= 0 && (! visited[i - 1][j]) && A[i - 1][j] == 'X') {
        dfs(i - 1, j, visited, A);
    }
    if (j - 1 >= 0 && (! visited[i][j - 1]) && A[i][j - 1] == 'X') {
        dfs(i, j - 1, visited, A);
    }
}

int Solution::black(vector<string> &A) {
    if (A.empty() || A[0].empty()) {
        return 0;
    }
    int ans = 0;
    int n = A.size();
    int m = A[0].size();
    vector <vector <int> > visited(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((! visited[i][j]) && A[i][j] == 'X') {
                dfs(i, j, visited, A);
                ans++;
            }
        }
    }
    return ans;
}
