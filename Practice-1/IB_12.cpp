//Min Xor Value

int Solution::findMinXor(vector<int> &A) {
    if (A.empty()) {
        return 0;
    }
    if (A.size() == 1) {
        return A[0];
    }
    sort(A.begin(), A.end());
    int ans = A[0] ^ A[1];
    for (int i = 2; i < A.size(); i++) {
        ans = min(ans, A[i] ^ A[i - 1]);
    }
    return ans;
}
