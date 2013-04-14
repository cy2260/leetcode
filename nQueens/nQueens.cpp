
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> sols;
        string row(n, '.');
        vector<string> sol(n, row);
        
        dfs( sols, sol, 0 );
        
        return sols;
    }
    
    bool canPlace( vector<string>& sol, int rowIdx, int colIdx ) {
        
        for( int i = 0; i < rowIdx; ++i ) {
            //check row
            if( sol[i][colIdx] == 'Q' ) return false;
            //check diagonal lines
            int idxDelta = rowIdx - i;
            if( colIdx + idxDelta < sol.size() && sol[i][colIdx+idxDelta] == 'Q' ) return false;
            if( colIdx - idxDelta >= 0 && sol[i][colIdx-idxDelta] == 'Q' ) return false;
        }
        return true;
    }
    
    void dfs( vector<vector<string>>& sols, vector<string>& sol, int rowIdx ) {
        if( rowIdx == sol.size() ) {
            sols.push_back( sol );
            return;
        }
        
        for( int colIdx = 0; colIdx < sol.size(); ++colIdx ) {
            if( canPlace( sol, rowIdx, colIdx ) ) {
                sol[rowIdx][colIdx] = 'Q';
                dfs( sols, sol, rowIdx+1 );
                sol[rowIdx][colIdx] = '.';
            }
        }
        
    }
};
