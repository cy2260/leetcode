class Solution {
public:
    bool isNumber(const char *s) {
        if( !s ) return false;
        
        while( s != '\0' && isspace(*s) ) ++s;
        if( *s == '-' || *s == '+' ) ++s;
        if( *s == '\0' ) return false;
        
        const char *end = s + strlen(s) - 1;
        while( end >= s && isspace(*end) ) --end;
        
        if( *end == 'e' )              return false;
        if( s == end && !isdigit(*s) ) return false;
        
        bool isNum = false;
        bool isExp = false;
        bool isDot = false;
        bool isSign = false;
        while( s <= end ) {
            if( isalpha(*s) && *s != 'e' ) return false;    
            if( isspace(*s) )              return false;
            
            if( isdigit(*s) ) {
                isNum = true;
            }
            else if( *s == '.' ) {
                if( isDot || isExp ) return false;
                isDot = true;
            }
            else if( *s == 'e' ) {
                if( isExp || !isNum ) return false;
                isExp = true;
    
            }
            else if( *s == '+' || *s == '-' ) {
                if( isSign ||  *(s-1) != 'e' ) return false;
                isSign = true;
            }
            else return false;
            
            ++s;
        }
         
        return true;
    }
};
