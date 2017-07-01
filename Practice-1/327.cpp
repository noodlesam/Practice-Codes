class Solution {
public:
    int solve(vector <long long> &sum, int lower, int upper, int low, int high) {
        if (low > high) {
            return 0;
        }
        if (low == high) {
            return (sum[low] >= lower && sum[low] <= upper) ? 1 : 0;
        }
        int mid = low + (high - low) / 2;
        int ans = solve(sum, lower, upper, low, mid) + solve(sum, lower, upper, mid + 1, high);
        int i = low;
        int j = mid + 1;
        int k = mid + 1;
        for (; i <= mid; i++) {
            while (j <= high && sum[j] - sum[i] < lower) {
                j++;
            }
            while (k <= high && sum[k] - sum[i] <= upper) {
                k++;
            }
            ans += (k - j);
        }
        vector <long long> temp(high - low + 1);
        for (i = k = low, j = mid + 1; k <= high; k++) {
            temp[k - low] = (i <= mid && (j > high || sum[i] < sum[j])) ? sum[i++] : sum[j++];
        }
        for (i = low; i <= high; i++) {
            sum[i] = temp[i - low];
        }
        return ans;
    }
    
    int countRangeSum(vector <int> &nums, int lower, int upper) {
        int n = nums.size();
        vector <long long> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = nums[i - 1] + sum[i - 1];
        }
        return solve(sum, lower, upper, 1, n);
    }
};
