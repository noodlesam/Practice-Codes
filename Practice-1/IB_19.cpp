//Highest product

int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    multiset <int> s;
    multiset <int> neg;
    for (int i = 0; i < n; i++) {
        if (s.size() < 3) {
            s.insert(A[i]);
        } else {
            int cur = *(s.begin());
            if (A[i] > cur) {
                s.erase(s.begin());
                s.insert(A[i]);
            }
        }
        if (A[i] < 0 && neg.size() < 2) {
            neg.insert(A[i]);
        } else if (A[i] < 0) {
            auto x = neg.end();
            x--;
            int cur = *x;
            if (A[i] < cur) {
                neg.erase(x);
                neg.insert(A[i]);
            }
        }
    }
    long long ans = 1;
    for (int x : s) {
        ans *= x;
    }
    if (neg.size() == 2) {
        auto x = s.end();
        x--;
        long long cur = *x;
        for (int x : neg) {
            cur *= x;
        }
        ans = max(ans, cur);
    }
    return ans;
}
