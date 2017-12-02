class Solution {
public:
    int reverse(int x) {
        int sign = (x < 0) ? -1 : 1;
        long long rev = 0;
        long long use = x * 1LL * sign;
        while (use > 0) {
            rev = rev * 10 + (use % 10);
            use /= 10;
        }
        rev *= sign;
        if (rev <= INT_MAX && rev >= INT_MIN) {
            return (int) rev;
        } else {
            return 0;
        }
    }
};
