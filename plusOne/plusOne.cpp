
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        int sum   = 0;
        vector<int> res(digits.size(),0);
        
        for( int i = digits.size() - 1; i >= 0; --i ) {
            sum   = carry + digits[i];
            carry = sum / 10;
            res[i] = sum % 10;
        }
        
        if( carry > 0 ) {
            res.insert( res.begin(), carry );
        }
        
        return res;
    }
};
