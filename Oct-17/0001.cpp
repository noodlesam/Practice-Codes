class Solution {
public:
    vector <int> twoSum(vector <int> &nums, int target) {
        vector <int> ans;
        unordered_map <int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i]) > 0) {
                ans = {m[target - nums[i]], i};
                return ans;
            }
            m[nums[i]] = i;
        }
    }
};
