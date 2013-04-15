
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if( prices.size() < 2 ) return 0;
        
        vector<int> left( prices.size() );
        vector<int> right( prices.size() );
        profitFromStart( prices, left );
        profitFromEnd( prices, right );
        
        int maxProfit = 0;
        for( int i = 0; i < prices.size(); ++i ) {
            int profit = left[i] + right[i];
            if( profit > maxProfit ) maxProfit = profit;
        }
        
        return maxProfit;
    }
    
    void profitFromStart( vector<int> &prices, vector<int> &left ) {
        int maxProfit = 0;
        int lowestPrice = INT_MAX;
        for( int i = 0; i < prices.size(); ++i ) {
            if( lowestPrice > prices[i] ) lowestPrice = prices[i];
            
            int profit = prices[i] - lowestPrice;
            
            if( profit > maxProfit ) maxProfit = profit;
        
            left[i] = maxProfit;
        }
    }
    
    void profitFromEnd(  vector<int> &prices, vector<int> &right ) {
        int maxProfit = 0;
        int highestPrice = 0;
        for( int i = prices.size() - 1; i >= 0; --i ) {
            if( highestPrice < prices[i] ) highestPrice = prices[i];
            
            int profit = highestPrice - prices[i];
            
            if( profit > maxProfit ) maxProfit = profit;
            
            right[i] = maxProfit;
        }
    }
};
