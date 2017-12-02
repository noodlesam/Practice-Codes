class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        vector <vector <bool> > isPalindrome(len + 1, vector <bool> (len + 1, false));
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
            if (i + 1 < len && s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
            }
        }
        for (int window = 3; window <= len; window++) {
            for (int i = 0; i <= len - window; i++) {
                int j = i + window - 1;
                if (s[i] == s[j] && isPalindrome[i + 1][j - 1]) {
                    isPalindrome[i][j] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (isPalindrome[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
