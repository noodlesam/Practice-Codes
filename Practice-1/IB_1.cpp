//N digit numbers with digit sum S

int get(int idx, int s, vector <vector <int> > &dp) {
    const int md = (int) 1e9 + 7;
    if (idx == 1) {
        if (s < 10) {
            return 1;
        } else {
            return 0;
        }
    }
    if (dp[idx][s] != -1) {
        return dp[idx][s];
    }
    dp[idx][s] = 0;
    for (int i = 0; i <= 9; i++) {
        if ((s - i) > 0 && (s - i - 1) / (idx - 1) < 9) { 
            dp[idx][s] += get(idx - 1, s - i, dp);
            if (dp[idx][s] >= md) {
                dp[idx][s] -= md;
            }
        }
    }
    return dp[idx][s];
}

int Solution::solve(int A, int B) {
    vector <vector <int> > dp(A + 1, vector <int> (B + 1, -1));
    return get(A, B, dp);
}
