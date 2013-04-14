
class Solution {
public:
    int charToInt( char c ) {
        return c - '0';
    }
    int atoi(const char *str) {
        if( !str ) return 0;
        
        int startIdx = 0;
        while( str[startIdx] == ' ' ) ++startIdx;
        
        if(str[startIdx] == '\0') return 0;
        
        bool isPositive = true;
        long long sum = 0;
        int len = strlen(str);
        
        for( int idx = startIdx; idx < len; ++idx ) {
            char temp = str[idx];
            if( idx == startIdx ) {
                if( temp == '-' )         isPositive = false;
                else if( temp == '+' )    isPositive = true;
                else if( !isdigit(temp) ) return 0;
                else                      sum += charToInt( temp );
            }
            else {
                if( temp == ',' )    continue; // 1,000,000 is valid
                if( !isdigit(temp) ) break;    //ignore following invalid part
                
                sum = 10*sum + charToInt( temp );
                
                //check if integer overflow
                if( isPositive && sum >= INT_MAX )   return INT_MAX;
                if( !isPositive && -sum <= INT_MIN ) return INT_MIN;
            }
        }         
        return  isPositive ? sum : 0 - sum;
    }
};
