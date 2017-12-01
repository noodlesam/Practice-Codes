class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> cnt;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i]]++;
            while (cnt[s[i]] > 1) {
                cnt[s[j]]--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
