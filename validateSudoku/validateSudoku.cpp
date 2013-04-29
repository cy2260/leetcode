class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rows = board.size();
        if( rows != 9 ) return false;
        int cols = board[0].size();
        if( cols != 9 ) return false;
        
        bool visited[10]; //val is from 1 to 9
        
        //validate rows
        for( int i = 0; i < rows; ++i ) {
            memset( visited, 0x00, sizeof(bool)*10 );
            for( int j = 0; j < cols; ++j ) {
                if( board[i][j] != '.' ) {
                    int val = board[i][j] - '0';
                    if( visited[val] ) return false;
                    else               visited[val] = true;    
                }
            }
        }
        
        //validate cols
        for( int i = 0; i < cols; ++i ) {
            memset( visited, 0x00, sizeof(bool)*10 );
            for( int j = 0; j < rows; ++j ) {
                if( board[j][i] != '.' ) {
                    int val = board[j][i] - '0';
                    if( visited[val] ) return false;
                    else               visited[val] = true;    
                }
            }
        }
        
        //validate block
        for( int i = 0; i < rows; i = i + 3 ) {
            for( int j = 0; j < cols; j = j + 3 ) {
               memset( visited, 0x00, sizeof(bool)*10 );
               for( int m = i; m < 3+i; ++m ) {
                   for( int n = j; n < 3+j; ++n ) {
                       if( board[m][n] != '.' ) { 
                           int val = board[m][n] - '0';
                           if( visited[val] ) return false;
                           else               visited[val] = true;
                       }
                   }
               }
            }
        }
        
        return true;
    }
};
