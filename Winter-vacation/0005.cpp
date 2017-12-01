class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int longest = 0;
        vector <vector <bool> > isPalindrome(len, vector <bool> (len, false));
        
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
            longest = max(longest, 1);
            if (i + 1 < len && s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                longest = 2;
            }
        }
        
        for (int window = 3; window <= len; window++) {
            for (int i = 0; i <= len - window + 1; i++) {
                if (s[i] == s[i + window - 1] && isPalindrome[i + 1][i + window - 2]) {
                    isPalindrome[i][i + window - 1] = true;
                    longest = window;
                }
            }
        }
        
        string ret;
        
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (isPalindrome[i][j] && j - i + 1 == longest) {
                    ret = s.substr(i, longest);
                    return ret;
                }
            }
        }
        
        return ret;
    }
};
