class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if( s.size() < 4 || s.size() > 12 ) return res;
        
        dfs( res, s, "", 0 );
        
        return res;
        
    }
    
    bool isValid( const string& str ) {
        int val = atoi(str.c_str());
        
        if( str[0] == '0' ) return str.size() == 1;
        
        return val <= 255 && val >0;
    }
    
    void dfs( vector<string>& res, string s, string ipstr, int idx ) {
        if( idx == 4 && s.size() == 0 ) {
            res.push_back( ipstr );
            
            return;
        }
        
        for( int i = 1; i <= 3 && i <= s.size(); ++i ) {
            string str = s.substr( 0, i );
            
            if( isValid( str ) ) {
                string tempStr = ipstr;
                
                ipstr.append( str );
                if( idx < 3 ) ipstr.push_back( '.' );
                
                dfs( res, s.substr(i), ipstr, idx+1 );
                
                ipstr = tempStr; //backtracking
            }
        }
    }
};
