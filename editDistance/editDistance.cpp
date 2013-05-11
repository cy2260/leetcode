class Solution {
public:
    int minDistance(string word1, string word2) {
        if( word1.size() == 0 ) return word2.size();
        if( word2.size() == 0 ) return word1.size();
        
        int w1Len = word1.size();
        int w2Len = word2.size();
        
        int dp[w1Len+1][w2Len+1];
        
        for( int i = 0; i <= w1Len; ++i ) {
            dp[i][0] = i;
        }
        for( int i = 0; i <= w2Len; ++i ) {
            dp[0][i] = i;
        }

        for( int i = 1; i <= w1Len; ++i ) {
            for( int j = 1; j <= w2Len; ++j ) {
                if( word1[i-1] == word2[j-1] ) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1])+1;
                }
            }
        }
        return dp[w1Len][w2Len];
    }
};
