#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {        
        assert( numbers.size() >= 2 );
        
        vector<int> res( 2, 0 );
        unordered_map<int, vector<int>> numMap;
       	
	//build a map, key is the number, value is idx+1
        for( int i = 0; i < numbers.size(); ++i ) {
            if( numMap.count( numbers[i] ) ) {
                numMap[numbers[i]].push_back( i + 1 );
            }
            else {
                numMap[numbers[i]] = vector<int>( 1, i + 1 );
            }
        }
                
        for( int i = 0; i < numbers.size(); ++i ) {
            if( numMap.count( target - numbers[i] ) ) {
                if( numbers[i] != target - numbers[i] ) {
                    res[0] = i + 1;
                    res[1] = numMap[ target - numbers[i] ][0];
                    return res;
                }
                else {
                    if( numMap[numbers[i]].size() > 1 ) {
                        res[0] = numMap[numbers[i]][0];
                        res[1] = numMap[numbers[i]][1];
                        return res;
                    }
                }
            }
        }
        return res;
    }
};

