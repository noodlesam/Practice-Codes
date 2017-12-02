class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        long long converted = 0;
        int i = 0;
        while (i < str.length() && str[i] == ' ') {
            i++;
        }
        if (i < str.length()) {
            if (str[i] == '-') {
                i++;
                sign = -1;
            } else if (str[i] == '+') {
                i++;
                sign = 1;
            }
        }
        while (i < str.length() && (str[i] >= '0' && str[i] <= '9')) {
            converted = converted * 10 + str[i] - '0';
            if (converted * 1LL * sign > INT_MAX) {
                return INT_MAX;
            }
            if (converted * 1LL * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return (int) (converted * 1LL * sign);
    }
};
