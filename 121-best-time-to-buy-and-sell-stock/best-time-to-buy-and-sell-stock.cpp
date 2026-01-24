class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = prices[0];
        int maxprofit = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] < minbuy){
                minbuy = prices[i];
            }
            else{
                int profit = prices[i] - minbuy;
                maxprofit = max(maxprofit, profit);
            }
        }
        return maxprofit;
    }
};