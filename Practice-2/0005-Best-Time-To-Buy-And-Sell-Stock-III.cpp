class Solution {
public:
    int maxProfit(vector <int> &prices) {
        vector <long long> cost(4, INT_MIN);
        for (auto cur : prices) {
            cost[3] = max(cost[3], cost[2] + cur);
            cost[1] = max(cost[1], cost[0] + cur);
            cost[2] = max(cost[2], cost[1] - cur);
            cost[0] = max(cost[0], -cur * 1LL);
        }
        cost[3] = max(cost[3], cost[1]);
        return (int) max(0LL, cost[3]);
    }
};
