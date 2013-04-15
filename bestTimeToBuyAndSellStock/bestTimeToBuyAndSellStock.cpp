
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if( prices.size() < 2 ) return 0;
        
        int lowestPrice = INT_MAX;
        int maxProfit = 0;
        
        for( int i = 0; i < prices.size(); ++i ) {
            if( prices[i] < lowestPrice ) lowestPrice = prices[i];
            
            int profit = prices[i] - lowestPrice;
            
            if( maxProfit < profit ) maxProfit = profit;
        }
        return maxProfit;
    }
};
