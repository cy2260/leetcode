
class Solution {
public:
    double pow(double x, int n) {
        double res = power( x, abs(n) );
        return n >= 0 ? res : 1/res;
    }
    
    double power( double x, int n ) {
        if( n == 0 ) return 1;
        
        double res = power( x, n/2 );
        
        if( n%2 == 0 ) return res * res;
        else           return res * res * x;
    }
};
