class Solution {
public:
    //start from center, low might equal to high
    string findPalindrome( const string& s, int low, int high ) {
        while( low >= 0 && high < s.size() ) {
            if( s[low] == s[high] ) {
                --low;
                ++high;
            }
            else {
                break;
            }
        }
        return s.substr( low+1, high-low-1 );
    }
    
    string longestPalindrome(string s) {
        if( s.empty() ) return "";
        if( s.size() == 1 ) return s;
        
        string res;
        for( int i = 0; i < s.size(); ++i ) {
            string tmp;
            tmp = findPalindrome( s, i, i );
            if( tmp.size() > res.size() ) res = tmp;
            
            tmp = findPalindrome( s, i, i+1 );
            if( tmp.size() > res.size() ) res = tmp;
        }
        return res;
    }
};
