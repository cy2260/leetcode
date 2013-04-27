class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        if( num.size() < 1 ) return res;
        sort( num.begin(), num.end() );
        perm( res, num, 0 );
    }
    
    void perm( vector<vector<int>>& res, vector<int>& num, int idx ) {
        if( idx == num.size() ) {
            res.push_back( num );
            return;
        }
        
        unordered_set<int> used;
        for( int i = idx; i < num.size(); ++i ) {
            if( used.find(num[i]) == used.end() )
            {
                used.insert(num[i]);
                swap( num[i], num[idx] );
                perm( res, num, idx+1 );
                swap( num[i], num[idx] );
            }
        }
    }
};
