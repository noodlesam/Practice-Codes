//Longest Arithmetic Progression

int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if (n <= 2) {
        return n;
    }
    vector <vector <int> > dp(n, vector <int> (n, 2));
    unordered_map <int, int> index;
    int ans = 2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = 2;
            int need = 2 * A[i] - A[j];
            if (index.count(need) > 0) {
                dp[i][j] = max(dp[i][j], dp[index[need]][i] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
        index[A[i]] = i;
    }
    return ans;
}
