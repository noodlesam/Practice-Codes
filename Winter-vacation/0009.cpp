class Solution {
public:
    bool isPalindrome(int x) {
        int cnt = 0;
        int firstHalf = x;
        while (x > 0) {
            x /= 10;
            cnt++;
        }
        int secondHalf = 0;
        for (int i = 0; i < cnt / 2; i++) {
            secondHalf = secondHalf * 10 + (firstHalf % 10);
            firstHalf /= 10;
        }
        if (cnt & 1) {
            firstHalf /= 10;
        }
        return firstHalf == secondHalf;
    }
};
