
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if( triangle.size() < 1 ) return 0;

        for( int rowIdx = triangle.size() - 2; rowIdx >= 0; --rowIdx ) {
            for( int colIdx = 0; colIdx < triangle[rowIdx].size(); ++colIdx ) {
                triangle[rowIdx][colIdx] += min( triangle[rowIdx+1][colIdx], triangle[rowIdx+1][colIdx+1] );
            }
        }
        return triangle[0][0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if( triangle.size() < 1 ) return 0;
        
        int numRows = triangle.size();
        vector<int> res = triangle[numRows-1];
        
        
        for( int rowIdx = numRows - 2; rowIdx >= 0; --rowIdx ) {
            for( int colIdx = 0; colIdx < triangle[rowIdx].size(); ++colIdx ) {
                res[colIdx] = triangle[rowIdx][colIdx] + min( res[colIdx], res[colIdx+1] );
            }
        }
        
        return res[0];
    }
};

