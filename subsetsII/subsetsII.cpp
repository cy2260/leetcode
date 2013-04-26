
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
        if( S.size() < 1 ) return res;
        
        sort(S.begin(), S.end());
        vector<int> sol;
        dfs( S, res, 0, sol );
        return res;
    }
    
    void dfs( vector<int> &S, vector<vector<int>>& res, int idx, vector<int>& sol ) {
        res.push_back( sol );
        
        for( int i = idx; i < S.size(); ++i ) {
            if( i == idx || S[i] != S[i-1] ) {
                sol.push_back(S[i]);
                dfs( S, res, i+1, sol );
                sol.pop_back();
            }
        }
        
    }     
};
