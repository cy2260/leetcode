
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

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> res;
        if( S.size() < 1 ) return res;
        
        sort(S.begin(), S.end());
        
        vector<bool> sol( S.size(), false );
        
        genSubsets( res, S, 0, sol );

        return res;
    }
    
    void genSubsets( vector<vector<int>>& res, vector<int> &S, int idx, vector<bool>& sol ) {
        if( idx == S.size() ) {
            vector<int> subset;
            for( int i = 0; i < sol.size(); ++i ) {
                if( sol[i] == true ) subset.push_back( S[i] );
            }
            res.push_back( subset );
            return;
        }
        
        genSubsets( res, S, idx+1, sol );
        sol[idx] = true;
        genSubsets( res, S, idx+1, sol );
        sol[idx] = false;
    }
};

