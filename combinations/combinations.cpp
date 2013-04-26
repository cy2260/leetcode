
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> res;
        if( n < 1 || k < 1 || n < k ) return res;
        
        vector<int> sol;
        
        dfs( res, sol, 1, n, k );
        
        return res;
    }
    
    void dfs( vector<vector<int>>& res, vector<int>& sol, int start, int n, int k ) {
        if( sol.size() == k ) {
            res.push_back(sol);
            return;
        }
        
        for( int i = start; i <= n; ++i ) {
            sol.push_back(i);
            dfs( res, sol, i+1, n, k );
            sol.pop_back();
        }
    }
};
