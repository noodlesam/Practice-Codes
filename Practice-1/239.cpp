class Solution {
public:
    vector <int> maxSlidingWindow(vector <int> &nums, int k) {
        vector <int> ans;
        if (nums.empty() || k == 0) {
            return ans;
        }
        multiset <int> window;
        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }
        for (int i = k; i <= nums.size(); i++) {
            auto it = window.end();
            ans.push_back(*(--it));
            window.erase(window.find(nums[i - k]));
            if (i < nums.size()) {
                window.insert(nums[i]);
            }
        }
        return ans;
    }
};
