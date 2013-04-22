
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        if( num.size() < 1 ) return res;
        
        perm( res, num, 0 );
    }
    
    void perm( vector<vector<int>>& res, vector<int>& num, int idx ) {
        if( idx == num.size() ) {
            res.push_back( num );
            return;
        }
        
        for( int i = idx; i < num.size(); ++i ) {
            swap( num[i], num[idx] );
            perm( res, num, idx+1 );
            swap( num[i], num[idx] );
        }
    }
}
