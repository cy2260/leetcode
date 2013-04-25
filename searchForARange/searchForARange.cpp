class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res( 2, -1 );
        if( !A || n < 1 ) return res;
        
        int lower = binarySearchLowerBound( A, n, target );
        int upper = binarySearchUpperBound( A, n, target );
        
        if( lower <= upper ) {        
            res[0] = lower;
            res[1] = upper;
        }
        
        return res;
    }
    
    int binarySearchLowerBound( int A[], int n, int target ) {
        int low  = 0;
        int high = n-1;
        while( low <= high ) {
            int mid = low + (high-low)/2;
            if( A[mid] >= target ) high = mid - 1;
            else                   low  = mid + 1;
        }
        return (high+1);
    }
    
    int binarySearchUpperBound( int A[], int n, int target ) {
        int low  = 0;
        int high = n-1;
        while( low <= high ) {
            int mid = low + (high-low)/2;
            if( A[mid] <= target ) low  = mid + 1;
            else                   high = mid - 1;
        }
        return (low-1);
    }
    
};

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        if( !A || n < 1 ) return res;
        
        int low = 0;
        int high = n - 1;
        int mid = 0;
        bool isFound = false;
        
        while( low <= high ) {
            mid = low + (high-low)/2;
            int val = A[mid];
            if( val == target ) {
                isFound = true;
                break;
            }
            else if( val < target ) ++low;
            else                    --high;
        }
        
        if( isFound ) {
            mid = low + (high-low)/2;
            low = mid;
            high = mid;
            while( low >=0 && A[low] == target ) --low;
            while( high < n && A[high] == target ) ++high;
            res[0] = low+1;
            res[1] = high-1;
        }
        return res;
    }
};
