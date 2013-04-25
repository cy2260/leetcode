
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> res(1);
        if( S.size() < 1 ) return res;
        
        sort(S.begin(), S.end());
        
        for( int i = 0; i < S.size(); ++i ) {
            int resLen = res.size();
            for( int j = 0; j < resLen; ++j ) {
                res.push_back( res[j] );
                res.back().push_back( S[i] );
            }
        }
        return res;
    }
};
