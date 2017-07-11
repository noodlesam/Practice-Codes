//Anagrams

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector <vector <int> > ans;
    unordered_map <string, int> m;
    int h[26];
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < 26; j++) {
            h[j] = 0;
        }
        for (int j = 0; j < A[i].size(); j++) {
            h[A[i][j] - 'a']++;
        }
        string key = "";
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < h[j]; k++) {
                key += (j + 'a');
            }
        }
        if (m.count(key) > 0) {
            ans[m[key]].push_back(i + 1);
        } else {
            vector <int> empty;
            ans.push_back(empty);
            m[key] = (int) ans.size() - 1;
            ans[m[key]].push_back(i + 1);
        }
    }
    return ans;
}
