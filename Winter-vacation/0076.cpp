class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char, int> cnt, m;
        for (char c : t) {
            m[c]++;
        }
        int cur = 0;
        int j = 0;
        pair <int, int> bestWindow = {0, INT_MAX};
        for (int i = 0; i < s.length(); i++) {
            if (cnt[s[i]] < m[s[i]]) {
                cur++;
            }
            cnt[s[i]]++;
            while (cur == t.length()) {
                if (i - j + 1 < bestWindow.second) {
                    bestWindow = {j, i - j + 1};
                }
                cnt[s[j]]--;
                if (cnt[s[j]] < m[s[j]]) {
                    cur--;
                }
                j++;
            }
        }
        if (bestWindow.second == INT_MAX) {
            return "";
        }
        return s.substr(bestWindow.first, bestWindow.second);
    }
};
