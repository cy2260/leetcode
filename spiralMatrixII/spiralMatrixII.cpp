class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        if( n < 1 ) return res;
        
        spiral( res, n, 1, 0 );
        return res;
    }
    
    void spiral( vector<vector<int> >& res, int n, int num, int idx ) {
        if( n == 0 ) return;
        if( n == 1 ) {
            res[idx][idx] = num++;
            return;
        }
        
        for( int i = idx; i < n+idx-1; ++i ) res[idx][i] = num++;
        for( int i = idx; i < n+idx-1; ++i ) res[i][n+idx-1] = num++;
        for( int i = n+idx-1; i > idx; --i ) res[n+idx-1][i] = num++;
        for( int i = n+idx-1; i > idx; --i ) res[i][idx] = num++;
        
        spiral( res, n-2, num, idx+1 );    
    }
};
