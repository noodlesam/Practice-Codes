class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map <char, int> m;
        for (int i = 0, j = 0; j < n; j++) {
            while (m[s[j]]) {
                m[s[i]]--;
                i++;
            }
            m[s[j]]++;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
