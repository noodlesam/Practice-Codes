class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector <int> h(26, 0);
        for (char x : p) {
            h[x - 'a']++;
        }
        vector <int> ans;
        vector <vector <int> > prefix(s.size() + 1, vector <int> (26, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < 26; j++) {
                prefix[i][j] = prefix[i - 1][j];
            }
            prefix[i][s[i - 1] - 'a']++;
            if (i - (int) p.size() >= 0) {
                bool ok = true;
                for (int j = 0; j < 26; j++) {
                    if (prefix[i][j] - prefix[i - (int) p.size()][j] != h[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans.push_back(i - (int) p.size());
                }
            }
        }
        return ans;
    }
};
