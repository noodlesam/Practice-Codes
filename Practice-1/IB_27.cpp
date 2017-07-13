//Interleaving Strings

int solve(string &A, string &B, string &C, int idx1, int idx2, vector <vector <int> > &dp) {
    if (idx1 == -1 && idx2 == -1) {
        return 1;
    }
    if (dp[idx1 + 1][idx2 + 1] != -1) {
        return dp[idx1 + 1][idx2 + 1];
    }
    int get = 0;
    if (idx1 >= 0 && C[idx1 + idx2 + 1] == A[idx1]) {
        get = get | solve(A, B, C, idx1 - 1, idx2, dp);
    }
    if (idx2 >= 0 && C[idx1 + idx2 + 1] == B[idx2]) {
        get = get | solve(A, B, C, idx1, idx2 - 1, dp);
    }
    return dp[idx1 + 1][idx2 + 1] = get;
}

int Solution::isInterleave(string A, string B, string C) {
    vector <vector <int> > dp(A.size() + 1, vector <int> (B.size() + 1, -1));
    return solve(A, B, C, (int) A.size() - 1, (int) B.size() - 1, dp);
}
