class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int rows = matrix.size();
        if( rows < 1 ) return res;
        int cols = matrix[0].size();
        if( cols < 1 ) return res;
        
        spiral( matrix, res, rows, cols, 0 );
        return res;        
    }
    
    void spiral( vector<vector<int> > &matrix, vector<int>& res, int rows, int cols, int idx ) {
        if( rows == 0 || cols == 0 ) return;
        if( rows == 1 ) {
            for( int i = idx; i < cols+idx; ++i ) {
                res.push_back( matrix[idx][i] );
            }
            return;
        }
        if( cols == 1 ) {
            for( int i = idx; i < rows+idx; ++i ) {
                res.push_back( matrix[i][idx] );
            }
            return;
        }
        
        for( int i = idx; i < cols+idx-1; ++i )  res.push_back( matrix[idx][i] );
        for( int i = idx; i < rows+idx-1; ++i )  res.push_back( matrix[i][cols+idx-1] );
        for( int i = cols+idx-1; i > idx; --i )  res.push_back( matrix[rows+idx-1][i] );
        for( int i = rows+idx-1; i > idx; --i )  res.push_back( matrix[i][idx] );
        
        spiral( matrix, res, rows-2, cols-2, idx+1 );
    }
};
