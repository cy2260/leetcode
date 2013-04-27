class Solution {
public:
    bool canJump(int A[], int n) {
        if( !A || n < 1 ) return false;
        
        int maxCover = 0;
        int idx = 0;
        while( idx < n && idx <= maxCover ) {
            maxCover = max( maxCover, (idx+A[idx]) );
            
            if( maxCover >= n-1 ) return true;
            
            ++idx;
        }
        
        return false;
    }
};

class Solution {
public:
    bool canJump(int A[], int n) {
        if( !A || n < 1 ) return true;
        int dp[n]; //max idx can reach
        dp[0] = A[0];

        for( int i = 1; i < n; ++i ) {
            if( dp[i-1] < i ) return false;
            dp[i] = max( i+A[i], dp[i-1] );
        }
        return true;
    }
};

