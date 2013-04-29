class Solution {
public:
    string countAndSay(int n) {
        if( n < 1 ) return "";
        
        string res("1");
        
        while( n > 1 ) {
            stringstream ss;
            
            int start = 0;
            while( start < res.size() ) {
                int end = start;
                //let end point to the first elem diff from start
                while( end < res.size() && res[end] == res[start] ) ++end;
                
                int count = end - start;
                ss << count << res[start];
                
                start = end;
            }
            
            res = ss.str();
            --n;
        }
        
        return res;
    }
};
