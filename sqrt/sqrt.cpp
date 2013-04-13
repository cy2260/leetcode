#include<iostream>
using namespace std;

class Solution {
public:
    int sqrt( int x ) {
    	if( x <= 1 ) return x;

	int start = 1;
	//avoid integer overflow of multiplication
	int end = x/2 < sqrt(INT_MAX) ? x/2+1 : sqrt(INT_MAX);

	while( start <= end ) {
	    int mid = start + ( end - start )/2;
	    if( mid * mid == x )      return mid;
	    else if ( mid * mid < x ) start = mid + 1;
	    else		      end = mid - 1;
	}
	return end; //always return end b/c end*end < x
    }
};
