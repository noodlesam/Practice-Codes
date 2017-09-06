class Solution {
public:
    bool ok(vector <string> &cur, int x, int y) {
        for (int i = 0; i < x; i++) {
            if (cur[i][y] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (cur[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < cur.size(); i--, j++) {
            if (cur[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    
    void solve(int idx, vector <string> &cur, vector <vector <string> > &ans) {
        int n = cur.size();
        if (idx == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < n; i++) {
            cur[idx][i] = 'Q';
            if (ok(cur, idx, i)) {
                solve(idx + 1, cur, ans);
            }
            cur[idx][i] = '.';
        }
    }
    
    vector <vector <string> > solveNQueens(int n) {
        string foo;
        for (int i = 0; i < n; i++) {
            foo += '.';
        }
        vector <string> cur(n, foo);
        vector <vector <string> > ans;
        solve(0, cur, ans);
        return ans;
    }
};
