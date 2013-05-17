class Solution {
public:
    string convert(string s, int nRows) {
        if( nRows < 2 ) return s;
        
        int sLen = s.size();
        int offset = nRows + ( nRows - 2 );
        
        string res;
        
        for( int i = 0; i < nRows; ++i ) {
            for( int j = i; j < sLen; j += offset ) {
                res.push_back(s[j]);
                //skip first and last row
                if( i == 0 || i == nRows-1 ) continue;
                
                int idx = j + offset - 2*i;
                if( idx < sLen ) res.push_back(s[idx]);
            }
        }
        
        return res;
    }
};
