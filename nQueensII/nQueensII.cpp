class Solution {
public:
    int totalNQueens(int n) {
        assert( n > 0 );
        
        int colOfRow[n];
        int numOfSols = 0;
        
        dfs( colOfRow, n, 0, numOfSols );
        
        return numOfSols;
    }
    
    bool canPlace( int* colOfRow, int n, int rowIdx, int colIdx ) {
        for( int i = 0; i < rowIdx; ++ i ) {
            if( colOfRow[i] == colIdx )                     return false;
            if( rowIdx - i == abs( colIdx - colOfRow[i] ) ) return false;
        }
        return true;
    }
    
    void dfs( int* colOfRow, int n, int rowIdx, int& numOfSols ) {
        if( rowIdx == n ) {
            ++numOfSols;
            return;
        }
        
        for( int colIdx = 0; colIdx < n; ++colIdx ) {
            if( canPlace( colOfRow, n, rowIdx, colIdx ) ) {
                colOfRow[rowIdx] = colIdx;
                dfs( colOfRow, n, rowIdx+1, numOfSols );
                colOfRow[rowIdx] = 0;
            }
        }
    }
    
};
