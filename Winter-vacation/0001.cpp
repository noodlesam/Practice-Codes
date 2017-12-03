class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        vector <int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(target - nums[i]) > 0) {
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            map[nums[i]] = i;
        }
    }
};
