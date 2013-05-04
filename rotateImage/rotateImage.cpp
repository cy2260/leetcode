class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if( n <= 1 ) return;    
        
        for( int i = 0; i < n; ++i ) {
            for( int j =0; j < n-i; ++j ) {
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
       
        for( int i = 0; i < n; ++i ) {
            int j = 0;
            int k = n-1;
            while( j <= k ) {
                swap(matrix[j][i], matrix[k][i]);
                j++;k--;
            }
        }
    }
};
