class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> resVec;
        if( n < 1 ) return resVec;
        
        int numOfLeftP  = 0;
        int numOfRightP = 0;
        
        string res( 2*n, ' ' );
        
        dfs( numOfLeftP, numOfRightP, res, resVec, 0, n );
        return resVec;    
    }
    
    void dfs( int numOfLeftP, int numOfRightP, string& res, 
            vector<string>& resVec, int idx, int n ) {
        
        if( numOfLeftP + numOfRightP == 2*n ) {
            resVec.push_back( res );
            return;
        }
        
        if( numOfLeftP < n ) {
            res[idx] = '(';
            dfs( numOfLeftP+1, numOfRightP, res, resVec, idx+1, n );
        }
        
        if( numOfRightP < numOfLeftP ) {
            res[idx] = ')';
            dfs( numOfLeftP, numOfRightP+1, res, resVec, idx+1, n );
        }
    }
};
