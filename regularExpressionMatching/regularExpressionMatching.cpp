//naive solution
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if( *p == '\0' ) return *s == '\0';
        
        if( *(p+1) != '*' ) {
            return ( *s == *p || ( *p == '.' && *s != '\0' ) ) && isMatch( s+1, p+1 );
        }
        else {
            while( *s == *p || ( *p == '.' && *s != '\0' )  ) {
                if( isMatch( s, p+2 ) ) return true;
                ++s;
           }
           return isMatch( s, p+2 );
        }
    }
};

//recursion + dp
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if( !s || !p ) return false;
        int rows = strlen(s) + 1;
        int cols = strlen(p) + 1;
        vector<vector<bool>> memo( rows, vector<bool>( cols, true ) );
        return isRegexMatch( s, p, memo );
    }
    
    bool isRegexMatch( const char *s, const char *p,  vector<vector<bool>>& memo ) {
        if( *p == '\0' ) return *s == '\0';
        if( memo[strlen(s)][strlen(p)] == false ) return false;
        
        if( *(p+1) != '*' ) {
            if ( ( *s == *p || ( *p == '.' && *s != '\0' ) ) && isRegexMatch( s+1, p+1, memo ) ) {
                memo[strlen(s)][strlen(p)] = true;
                return true;
            }
            else {
                memo[strlen(s)][strlen(p)] = false;
                return false;
            }
        }
        else {
            while( *s == *p || ( *p == '.' && *s != '\0' )  ) {
                if( isRegexMatch( s, p+2, memo ) ) {
                    memo[strlen(s)][strlen(p)] = true;
                    return true;
                }                
                else {
                    memo[strlen(s)][strlen(p)] = false;
                }
                ++s;
           }
           
           if( isRegexMatch( s, p+2, memo ) ) {
               memo[strlen(s)][strlen(p)] = true;
               return true;
           }
           else {
               memo[strlen(s)][strlen(p)] = false;
               return false;
           }  
        }
    }
};

