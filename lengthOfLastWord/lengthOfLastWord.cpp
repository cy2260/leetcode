
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if( !s || *s == '\0' ) return 0;
        
        int idx = strlen(s) - 1;
        
        while( idx >= 0 && s[idx] == ' ' ) --idx;
        
        int end = idx;
        
        while( idx >= 0 && s[idx] != ' ' ) --idx;
        
        return end - idx; 
    }
};
