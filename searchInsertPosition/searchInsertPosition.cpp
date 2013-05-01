class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if( !A || n < 1 ) return 0;
        
        int low  = 0;
        int high = n-1;
        
        while( low <= high ) {
            int mid = low + (high-low)/2;
            if( A[mid] == target )     return mid;
            else if( A[mid] < target ) low  = mid + 1;
            else                       high = mid - 1;
        }
        return low;
    }
};
