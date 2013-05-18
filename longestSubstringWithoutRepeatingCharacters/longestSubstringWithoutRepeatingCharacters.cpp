class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.size() < 2 ) return s.size();
        unordered_map<char,bool> charMap;
        queue<char> substrQ;
        int maxLen = 1;
        for( int i = 0; i < s.size(); ++i ) {
            
            if( charMap[s[i]] == true ) {
                while( charMap[s[i]] == true && substrQ.size() ) {
                    char c = substrQ.front();
                    substrQ.pop();
                    charMap[c] = false;
                }
            }
          
            charMap[s[i]] = true;
            substrQ.push(s[i]);
            if( substrQ.size() > maxLen ) maxLen = substrQ.size();    
        }
 
        return maxLen;
    }
};
