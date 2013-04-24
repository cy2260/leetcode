
class Solution {
public:
    unordered_map<int, int> resMap;
    int numTrees(int n) {
        if( n == 0 || n == 1 ) return 1;
        
        if( resMap.find( n ) != resMap.end() ) {
            return resMap[n];
        }
        
        int count = 0;
        for( int i = 0; i < n; ++i ) {
            count += numTrees( i ) * numTrees( n-i-1 );
        }
        resMap[n] = count;
        
        return count;  
    }
};


class Solution {
public:

    int numTrees(int n) {
        if( n == 0 || n == 1 ) return 1;
        int dp[n+1];
        memset( dp, 0, sizeof(int)*(n+1) );
        
        dp[0] = dp[1] = 1;
    
        for( int i = 2; i <= n; ++i ) {
            for( int j = 0; j < i; ++j ) {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        
        return dp[n];     
    }
};
