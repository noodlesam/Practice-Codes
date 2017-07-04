//Max sum without adjacent elements

int Solution::adjacent(vector<vector<int> > &A) {
    if (A.empty()) {
        return 0;
    }
    int n = A[0].size();
    int dp[2][n + 2];
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < 2; j++) {
            dp[j][i] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[j][i + 1] = max(dp[j][i + 1], dp[j][i + 1 - 2] + A[j][i - 1]);
            dp[j][i + 1] = max(dp[j][i + 1], dp[j ^ 1][i + 1 - 2] + A[j][i - 1]);
            dp[j][i + 1] = max(dp[j][i + 1], dp[j][i]);
            dp[j][i + 1] = max(dp[j][i + 1], dp[j ^ 1][i]);
            ans = max(ans, dp[j][i + 1]);
        }
    }
    return ans;
}
