class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cnt = 0;
        unordered_map <int, int> cache;
        cache[0] = 1;
        for (int x : nums) {
            sum += x;
            cnt += cache[sum - k];
            cache[sum]++;
        }
        return cnt;
    }
};
