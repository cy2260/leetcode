class Solution {
public:
    void sortColors(int A[], int n) {
        if( !A || n < 1 ) return;
        
        int* count = new int[3];
        memset( count, 0x00, sizeof(int)*3);
        
        for( int i = 0; i < n; ++i ) {
            ++count[A[i]];
        }
        
        int idx = 0;
        for( int i = 0; i < 3; ++i ) {
            while( count[i] > 0 ) {
                A[idx++] = i;
                count[i]--;
            }
        }
        delete count;
    }
};
