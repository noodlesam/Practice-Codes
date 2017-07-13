//Largest Continuous Sequence Zero Sum

vector<int> Solution::lszero(vector<int> &A) {
    int len = 0;
    pair <int, int> _range = {-1, -1};
    unordered_map <long long, int> m;
    m[0] = -1;
    long long cur = 0;
    for (int i = 0; i < A.size(); i++) {
        cur += A[i];
        if (m.count(cur) > 0) {
            if (len < i - (m[cur] + 1) + 1) {
                len = i - (m[cur] + 1) + 1;
                _range = {m[cur] + 1, i};
            }
        } else {
            m[cur] = i;
        }
    }
    vector <int> ans;
    for (int i = _range.first; i <= _range.second; i++) {
        if (i >= 0) {
            ans.push_back(A[i]);
        }
    }
    return ans;
}
