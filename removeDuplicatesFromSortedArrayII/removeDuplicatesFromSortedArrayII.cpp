
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( !A || n <= 2 ) return n;
        
        int curIdx = 1;
        for( int idx = 2; idx < n; ++idx ) {
            if( A[curIdx] != A[idx] || A[curIdx] != A[curIdx-1] ) {
                A[++curIdx] = A[idx];
            }
        }
        return curIdx+1;
    }
};

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( !A || n <= 2 ) return n;
        
        int curIdx = 0;
        int count = 0;
        
        for( int idx = 1; idx < n; ++idx ) {
            if( A[curIdx] == A[idx] ) {
                ++count;
                
                if( count > 1 ) continue;
            }
            else {
                count = 0;
            }
            
            A[++curIdx] = A[idx];
        }
        return curIdx+1;
    }
};

