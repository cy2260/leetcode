
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        if( num.size() < 3 ) return res;
        
        sort( num.begin(), num.end() );
        
        for( int i = 0; i < num.size(); ++i ) {
            int target = num[i];
            int low  = i + 1;
            int high = num.size() - 1;
            
            vector<int> sol( 3 );
            while( low < high ) {
                if( num[low] + num[high] + target == 0 ) {
                    sol[0] = target;
                    sol[1] = num[low];
                    sol[2] = num[high];
                    res.push_back( sol );
                    ++low;--high;
                    //filter duplicated solutions as current one
                    //example, [-1, 0, 0, 1, 1 ], case i=1;low=2;high=3 needs to be ignored
                    while( low < high && num[low] == num[low-1] )   ++low;
                    while( low < high && num[high] == num[high+1] ) --high;
                }
                else if( num[low] + num[high] + target < 0 ) {
                    ++low;
                }
                else {
                    --high;
                }
                
            }
            //filter duplicated num[i]
            //example, [-1, -1, -1, 0, 1], second and third element need to be ignored
            if( i < num.size() - 1 ) {
                while( num[i] == num[i+1] ) ++i;
            }
        }
        return res;       
    }
};
