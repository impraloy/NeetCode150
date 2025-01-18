/*
Test Case 1:
Input: prices = [10,1,5,6,7,1]
Output: 6

Test Case 2:
Input: prices = [10,8,7,5,2]
Output: 0
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxProfit = 0;

        while(r <prices.size()){
            if(prices[l] < prices[r]){
                int profit = prices[r]-prices[l];
                maxProfit = max(maxProfit, profit);
            }else{
                l = r;
            }
            r++;
        }
        return maxProfit;
        
    }
};
