class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        if( rows == 0 ) return false;
        int cols = matrix[0].size();
        if( cols == 0 ) return false;
        
        for( int i = 0; i < rows; ++i ) {
            if( target <= matrix[i][cols-1] ) {
                return binarySearch( matrix[i], target );
            }
        }
        
        return false;
    }
    
    bool binarySearch( vector<int> &vec, int target ) {
        int low  = 0;
        int high = vec.size() - 1;
        while( low <= high ) {
            int mid = low+(high-low);
            if( vec[mid] == target )     return true;
            else if( vec[mid] < target ) low = mid+1;
            else                         high = mid-1;
        }
        return false;
    }
};
