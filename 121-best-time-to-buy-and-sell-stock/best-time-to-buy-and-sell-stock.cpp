class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int minbuy = arr[0];
        int maxprofit = 0;
        for(int i = 1; i<arr.size();i++){
            if(arr[i] < minbuy){
                minbuy = arr[i];
            }
            else{
                int profit = arr[i] - minbuy;
                maxprofit = max(maxprofit, profit);
            }
        }
        return maxprofit;
    }
};