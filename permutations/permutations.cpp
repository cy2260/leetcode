
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


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        if( num.size() < 1 ) return res;
        
        vector<int> solution( num.size() );
        vector<bool> visited( num.size(), false );
        
        perm( res, num, 0, solution, visited );
        
        return res;
    }
    
    void perm( vector<vector<int>>& res, vector<int>& num, int idx, vector<int>& solution, vector<bool>& visited ) {
        if( idx == num.size() ) {
            res.push_back( solution );
            return;
        }
        
        for( int i = 0; i < num.size(); ++i ) {
            if( visited[i] == false ) {
                visited[i] = true;
                solution[idx] = num[i];
                perm( res, num, idx+1, solution, visited );
                visited[i] = false;
            }
        }
    }
};

