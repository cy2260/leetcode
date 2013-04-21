
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        if( len < 1 ) return true;
        
        int low  = 0;
        int high = len - 1;
        
        while( low <= high ) {
            while( low<=high && !isalpha(s[low]) && !isdigit(s[low]) )
                ++low;
            while( low<=high && !isalpha(s[high]) && !isdigit(s[high]) )
                --high;
                
            if( low <= high ) {
                if( toupper(s[low++]) != toupper(s[high--]) ) return false;
            }
            else  return true;
        }
        return true;
    }
};
