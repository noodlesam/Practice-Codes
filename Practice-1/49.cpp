//Group anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, int> m;
        vector <vector <string> > ans;
        for (string x : strs) {
            vector <int> h(26, 0);
            for (char c : x) {
                h[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < h[i]; j++) {
                    key += (i + 'a');
                }
            }
            if (! m.count(key)) {
                vector <string> dummy;
                dummy.push_back(x);
                ans.push_back(dummy);
                m[key] = (int) ans.size() - 1;
            } else {
                ans[m[key]].push_back(x);
            }
        }
        return ans;
    }
};
