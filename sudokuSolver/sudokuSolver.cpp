class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        for( int i = 0; i < 9; ++i ) {
            for( int j = 0; j < 9; ++j ) {
                if( board[i][j] == '.' ) {
                    for( int k = 1; k <= 9; ++k ) {
                        board[i][j] = k + '0';
                        if( isValid( board, i, j ) && solveSudoku( board ) )
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isValid( vector<vector<char> > &board, int row, int col ) {
        char val = board[row][col];
        for( int i = 0; i < 9; ++i ) {
            if( i != col && board[row][i] == val ) return false;
            if( i != row && board[i][col] == val ) return false;
            int m = row/3*3 + i/3;
            int n = col/3*3 + i%3;
            if( m != row && n != col && board[m][n] == val ) return false;
        
        }
        return true;
    }
};
