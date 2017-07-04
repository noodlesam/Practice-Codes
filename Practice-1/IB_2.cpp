//Repeating subsequences

int Solution::anytwo(string A) {
    int n = A.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                if (A[i - 1] == A[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    if (ans > 1) {
        return 1;
    }
    return 0;
}
