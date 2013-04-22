class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if( rowIndex < 0 ) return res;
        
        res.resize( rowIndex + 1 );
        
        for( int i = 0; i <= rowIndex; ++i ) {
            for( int j = i; j >= 0; --j ) {
                if( j == 0 || j == i ) res[j] = 1;
                else                   res[j] = res[j] + res[j-1];
            }
        } 
        
        return res;
    }
};

