
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res;
        if( numRows < 1 ) return res;
        
        for( int i = 0; i < numRows; ++i ) {
            vector<int> row(i+1, 0);
            for( int j = 0; j <= i; ++j ) {
                if( j == 0 || j == i ) row[j] = 1;
                else                   row[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back( row );
        }
        return res;
    }
};
