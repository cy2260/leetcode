
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int endIdx = m + n - 1;
        int aIdx = m - 1;
        int bIdx = n - 1;
        while( aIdx >= 0 && bIdx >=0 ) {
            if( A[aIdx] > B[bIdx] ) A[endIdx--] = A[aIdx--];
            else                    A[endIdx--] = B[bIdx--];
        }
        while( aIdx >= 0 ) A[endIdx--] = A[aIdx--];
        while( bIdx >= 0 ) A[endIdx--] = B[bIdx--];    
    }
};
