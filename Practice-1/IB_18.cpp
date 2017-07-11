//Distinct numbers in window

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector <int> ans;
    if (B > A.size()) {
        return ans;
    }
    unordered_map <int, int> m;
    int cnt = 0;
    for (int i = 0; i < B; i++) {
        if (! m[A[i]]) {
            cnt++;
        }
        m[A[i]]++;
    }
    ans.push_back(cnt);
    for (int i = B; i < A.size(); i++) {
        m[A[i - B]]--;
        if (! m[A[i - B]]) {
            cnt--;
        }
        if (! m[A[i]]) {
            cnt++;
        }
        m[A[i]]++;
        ans.push_back(cnt);
    }
    return ans;
}
