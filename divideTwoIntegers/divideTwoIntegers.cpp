class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend^divisor)>>31 ? -1 : 1;
        
        long long posDividend = abs((long long)dividend);
        long long posDivisor  = abs((long long)divisor);
        long long quotient    = 1;
        
        while( posDividend > posDivisor ) {
            posDivisor <<= 1;
            quotient   <<= 1;
        }
        
        int result = 0;
        while( posDivisor > 0 ) {
            if( posDividend >= posDivisor ) {
                posDividend -= posDivisor;
                result |= quotient;
            }
            quotient   >>= 1;
            posDivisor >>= 1;
        }
        
        return sign*result; 
    }
};
