
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if( !A || n < 1 ) return 0;
        
        int idx = 0;
        
        for( int i = 0; i < n; ++i ) {
            if( A[i] != elem ) {
                A[idx] = A[i];
                ++idx;
            }
        }
        
        return idx;
    }
};
