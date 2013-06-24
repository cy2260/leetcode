class Solution {
public:
    int maxSubArray(int A[], int n) {
        if( !A || n < 1 ) return -1;
        
        int maxSum = A[0];
        
        int preSum = A[0];
        
        for( int i = 1; i < n; ++i ) {
            if( preSum > 0 && preSum+A[i] > 0 ) {
                preSum += A[i];
            }
            else {
                preSum = A[i];
            }
            
            maxSum = max( maxSum, preSum );
        }
        return maxSum;
    }
};
