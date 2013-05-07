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
