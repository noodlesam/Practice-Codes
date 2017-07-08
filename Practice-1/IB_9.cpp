//Sum of fibonacci numbers

void solve(vector <int> &fib, int idx, int cur, int curans, int A, int &ans) {
    if (ans != -1) {
        return;
    }
    if (idx >= 0) {
        if (cur + fib[idx] <= A) {
            solve(fib, idx, cur + fib[idx], curans + 1, A, ans);
        }
        solve(fib, idx - 1, cur, curans, A, ans);
    } else if (cur == A) {
        ans = curans;
    }
}

int Solution::fibsum(int A) {
    vector <int> fib;
    fib.push_back(1);
    int fr = 1, sec = 1;
    while (fr + sec <= A) {
        int cur = fr + sec;
        fib.push_back(cur);
        fr = sec;
        sec = cur;
    }
    int ans = -1;
    solve(fib, (int) fib.size() - 1, 0, 0, A, ans);
    return max(0, ans);
}
