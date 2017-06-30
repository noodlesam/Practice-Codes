class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) {
            return 0;
        }
        int n = M.size();
        int m = M[0].size();
        int dp[n + 2][m + 2][4];
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                for (int k = 0; k < 4; k++) {
                    dp[i][j][k] = 0;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (M[i - 1][j - 1]) {
                    dp[i][j][0] = dp[i - 1][j][0] + 1;
                    dp[i][j][1] = dp[i][j - 1][1] + 1;
                    dp[i][j][2] = dp[i - 1][j - 1][2] + 1;
                    dp[i][j][3] = dp[i - 1][j + 1][3] + 1;
                }
                for (int k = 0; k < 4; k++) {
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
        return ans;
    }
};
