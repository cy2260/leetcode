class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;
        
        int idx = 0;
        while( idx < path.size() ) {
            if( path[idx] != '/' ) {
                
                int start = idx;
                while( path[idx] != '/' ) ++idx;
                
                string str = path.substr( start, idx-start );
                if( str == ".." ) {
                    if( s.size() > 0 ) s.pop_back();
                }
                else if( str != "."  ) s.push_back( str );
            }
            
            ++idx;
        }
        
        if( s.size() == 0 ) return "/";
        
        string res;
        while( s.size() ) {
            res += "/"+s.front();
            s.pop_front();
        }
        
        return res;
    }
};
