class Solution {
public:
    int permutation(int n, int r) {
        if (r == 0) {
            return 1;
        }
        return n * permutation(n - 1, r - 1);
    }
    
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        n = min(n, 10);
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            ans += 9 * permutation(9, i - 1);
        }
        return ans;
    }
};
