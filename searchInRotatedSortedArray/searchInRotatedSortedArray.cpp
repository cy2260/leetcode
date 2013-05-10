class Solution {
public:
    int search(int A[], int n, int target) {
        if( !A || n < 1 ) return -1;
        
        int low  = 0;
        int high = n - 1;
        
        while( low <= high ) {
            int mid = low + (high-low)/2;
            if( A[mid] == target ) return mid;
            
            if( A[low] <= A[mid] ) { //left half is sorted
                if( A[low] <= target && target < A[mid] ) high = mid - 1; //like normal binary search
                else                                      low  = mid + 1; //search the other half
            }
            else { //right half is sorted
                if( A[mid] < target && target <= A[high] ) low  = mid + 1; //like normal binary search
                else                                       high = mid - 1; //search the other half 
            }
        }
        
        return -1;
    }
};
