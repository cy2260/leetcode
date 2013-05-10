class Solution {
public:
    bool search(int A[], int n, int target) {
        if( !A || n < 1 ) return false;
        
        int low  = 0;
        int high = n - 1;
        
        while( low <= high ) {
            int mid = low + (high-low)/2;
            if( A[mid] == target ) return true;
            
            if( A[low] == A[mid] )       ++low;
            else if( A[mid] == A[high] ) --high;
            else if( A[low] < A[mid] ) { //left half is sorted
                if( A[low] <= target && target < A[mid] ) high = mid - 1;
                else                                      low  = mid + 1;
            }
            else { //right half is sorted
                if( A[mid] < target && target <= A[high] ) low  = mid + 1;
                else                                       high = mid - 1;
            }
        }
        return false;
    }
};
