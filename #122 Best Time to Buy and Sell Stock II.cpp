class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max = 0;
        int buy = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                max += prices[i] - buy;
                buy = prices[i];
            }
        }
        return max;
    }
};
