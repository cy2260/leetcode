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

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solveHelper( board, 0, 0 );
    }
    
    bool solveHelper( vector<vector<char> > &board, int row, int col ) {
        if( !findNextPosition( board, row, col ) ) return true; //no empty position, solved
        
        vector<char> nums;
        getValidNums( board, nums, row, col );
        for( int i = 0; i < nums.size(); ++i ) {
            board[row][col] = nums[i];
            if( solveHelper( board, row, col ) ) return true;
            board[row][col] = '.';
        }
        return false;
    }
    
    bool findNextPosition( vector<vector<char> > &board, int& row, int& col ) {
        for( int i = 0; i < 9; ++i ) {
            for( int j = 0; j < 9; ++j ) {
                if( board[i][j] == '.' ) {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }
    
    void getValidNums( vector<vector<char> > &board, vector<char>& nums, int row, int col ) {
        bool used[10] = {false};
        for( int i = 0; i < 9; ++i ) {
            if( board[row][i] != '.' )  used[board[row][i]-'0'] = true;
            if(  board[i][col] != '.' ) used[board[i][col]-'0'] = true;
            int m = row/3*3 + i/3;
            int n = col/3*3 + i%3;
            if( board[m][n] != '.' )    used[board[m][n]-'0'] = true;
        }
        
        for( int i = 1; i <= 9; ++i ) {
            if( used[i] == false ) nums.push_back( i+'0' );
        }
    }
};

