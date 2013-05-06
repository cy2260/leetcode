class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if( !A || n < 1 ) return 1;
        
        int idx = 0;
        while( idx < n ) {
            if( A[idx] > 0 && A[idx] < n && A[idx] != A[A[idx]-1] ) {
                swap( A[idx], A[A[idx]-1] );
            }
            else  ++idx;
        }
        
        for( idx = 0; idx < n; ++idx ) {
            if( A[idx] != idx+1 ) break;
        }
        
        return idx+1;
    }
};
