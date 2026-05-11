class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 0;
        int maxProfit = 0;
        while (buy <= sell && sell < prices.size()) {
            if (prices[sell] < prices[buy]) {
                buy = sell;
            } 
            maxProfit = max(maxProfit, prices[sell] - prices[buy]);
            sell++;
        }
        return maxProfit;
    }
};
