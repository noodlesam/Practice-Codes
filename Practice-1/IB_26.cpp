//Distinct Subsequences

int countWays(string &S, string &T, int idx1, int idx2, vector <vector <int> > &dp) {
    if (idx2 < 0) {
        return 1;
    }
    if (idx1 < 0) {
        return 0;
    }
    if (dp[idx1][idx2] != -1) {
        return dp[idx1][idx2];
    }
    dp[idx1][idx2] = 0;
    if (S[idx1] == T[idx2]) {
        dp[idx1][idx2] += countWays(S, T, idx1 - 1, idx2 - 1, dp);
    }
    dp[idx1][idx2] += countWays(S, T, idx1 - 1, idx2, dp);
    return dp[idx1][idx2];
}

int Solution::numDistinct(string S, string T) {
    vector <vector <int> > dp(S.size(), vector <int> (T.size(), -1));
    countWays(S, T, (int) S.size() - 1, (int) T.size() - 1, dp);
    return dp[(int) S.size() - 1][(int) T.size() - 1];
}
