class Solution {
public:
    string addBinary(string a, string b) {
        if( a.size() == 0 ) return b;
        if( b.size() == 0 ) return a;
        
        int maxLen = max( a.size(), b.size() );
        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );
        
        string res;
        int carry = 0;
        int idx = 0;

        while( idx < maxLen ) {
            int elemA = idx < a.size() ? a[idx]-'0' : 0;
            int elemB = idx < b.size() ? b[idx]-'0' : 0;
            int sum   = (elemA + elemB + carry)%2;
            carry = (elemA + elemB + carry)/2;
            res.push_back( sum+'0' );
            ++idx;
        }
        if( carry ) res.push_back( '1' );
        
        reverse( res.begin(), res.end() );
        
        return res;
    }
};
