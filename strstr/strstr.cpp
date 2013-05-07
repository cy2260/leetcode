class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        //if target str is empty, return haystack
        if( !haystack || !needle ) return haystack;
        
        int hLen = strlen(haystack);
        int nLen = strlen(needle);
        
        if( hLen < nLen ) return NULL;
        
        int hIdx = 0;
        while( hIdx < hLen - nLen + 1 ) {
            int nIdx = 0;
            while( nIdx < nLen && haystack[hIdx] == needle[nIdx] ) {
                ++hIdx;
                ++nIdx;
            }
            if( nIdx == nLen ) return haystack+hIdx-nIdx;
            else               hIdx = hIdx-nIdx+1;
        } 
        return NULL;
    }
};

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        //if target str is empty, return haystack
        if( !haystack || !needle ) return haystack;
        if( *needle == '\0' )      return haystack;
        
        char* tmp = needle;
        char* stopPtr = haystack;
        while( *tmp != '\0' ) {
            ++tmp;
            ++stopPtr;
        }
        --stopPtr; //equivalent to strlen(haystack) - strlen(needle)
        
        while( *stopPtr != '\0' ) {
            char *source = haystack;
            char *target = needle;
            while( *target != '\0' && *source == *target ) {
                ++source;
                ++target;
            }
            if( *target == '\0' ) return haystack;
            
            ++haystack;
            ++stopPtr;
        } 
        return NULL;
    }
};

