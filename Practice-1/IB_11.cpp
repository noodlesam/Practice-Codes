//Coins in a line

int Solution::maxcoin(vector <int> &A) {
    int n = A.size();
    if (n == 0) {
        return 0;
    }
    vector <vector <int> > dp(n, vector <int> (n, 0));
    for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            int x = 0;
            int y = 0;
            int z = 0;
            if (i + 2 <= j) {
                x = dp[i + 2][j];
                y = dp[i + 1][j - 1];
                z = dp[i][j - 2];
            }
            dp[i][j] = max(A[i] + min(x, y), A[j] + min(y, z));
        }
    }    
    return dp[0][n - 1];
}
