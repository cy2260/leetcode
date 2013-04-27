
class Solution {
public:
    int jump(int A[], int n) {
        if( !A || n < 1 ) return 0;
        
        int steps     = 0;
        int maxReach  = 0;
        int lastReach = 0;
        
        for( int i = 0; i < n; ++i ) {
            
            if( maxReach < i ) return 0; //cannot reach current idx
            
            if( i > lastReach ) {
                ++steps; //need another jump
                lastReach = maxReach;
            }
            
            maxReach = max( maxReach, (i+A[i]) );
        }
        return steps;
    }
};
