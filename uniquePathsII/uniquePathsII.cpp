
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int rows = obstacleGrid.size();
        if( rows < 1 ) return 0;
        int cols = obstacleGrid[0].size();
        if( cols < 1 ) return 0;
        
        int dp[rows][cols];
        
        int cellVal = 1;
        for( int i = 0; i < cols; ++i ) {
            if( obstacleGrid[0][i] == 1 ) cellVal = 0; 
            dp[0][i] = cellVal;
        }
        cellVal = 1;
        for( int i = 0; i < rows; ++i ) {
            if( obstacleGrid[i][0] == 1 ) cellVal = 0;
            dp[i][0] = cellVal;
        }
        
        for( int i = 1; i < rows; ++i ) {
            for( int j = 1; j < cols; ++j ) {
                if( obstacleGrid[i][j] == 1 ) dp[i][j] = 0;
                else                          dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[rows-1][cols-1];
    }
};
