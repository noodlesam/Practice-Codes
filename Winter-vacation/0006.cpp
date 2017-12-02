class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector <string> ret(numRows);
        int pos = -1;
        int dir = 0;
        for (int i = 0; i < s.length(); i++) {
            if (pos == numRows - 1) {
                dir = 1;
            } else if (pos == 0) {
                dir = 0;
            }
            if (dir == 0) {
                pos++;
            } else {
                pos--;
            }
            ret[pos] += s[i];
        }
        string ans;
        for (auto str : ret) {
            ans += str;
        }
        return ans;
    }
};
