
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( !A || n < 1 ) return 0;
        
        int idx = 0;
        for( int i = 0; i < n; ++i ) {
            if( i != 0 &&  A[idx] != A[i] ) {
                A[++idx] = A[i];
            }
        }
        return idx+1;
    }
};
