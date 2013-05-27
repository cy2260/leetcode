class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if( num.size() < 1 ) return 0;
        if( num.size() == 1 ) return 1;
        
        int maxLen = 1;
        unordered_map<int, int> hashMap;
        
        for( int i = 0; i < num.size(); ++i ) {
            if( hashMap.find(num[i]) != hashMap.end() ) continue;
            
            hashMap[num[i]] = 1;
            
            if( hashMap.find(num[i]-1) != hashMap.end() ) {
                int len = getMaxLen( hashMap, num[i]-1, num[i] );
                maxLen = max( len, maxLen );
            }
            
            if( hashMap.find(num[i]+1) != hashMap.end() ) {
                int len = getMaxLen( hashMap, num[i], num[i]+1 );
                maxLen = max( len, maxLen );
            }
            
            
        }
        
        return maxLen;
    }
    
    int getMaxLen( unordered_map<int, int>& hashMap, int low, int high ) {
        int lowest  = low  - hashMap[low]  + 1;
        int highest = high + hashMap[high] - 1;
        
        int len = highest - lowest + 1;
        
        hashMap[lowest] = len;
        hashMap[highest] = len;
        
        return len;
    }
};
