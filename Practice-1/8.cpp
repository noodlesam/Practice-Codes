class Solution {
public:
    int myAtoi(string str) {
        long long num = 0;
        int sign = 1;
        int start = 0;
        while (start < str.size() && str[start] == ' ') {
            start++;
        }
        if (str[start] == '-') {
            start++;
            sign = -1;
        } else if (str[start] == '+') {
            start++;
        }
        while (start < str.size() && str[start] >= '0' && str[start] <= '9') {
            num = num * 10 + str[start] - '0';
            if (sign * num > INT_MAX) {
                return INT_MAX; 
            }
            if (sign * num < INT_MIN) {
                return INT_MIN;
            }
            start++;
        }
        return (int) (sign * num);
    }
};
