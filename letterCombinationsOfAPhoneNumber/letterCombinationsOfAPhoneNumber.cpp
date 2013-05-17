class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> solVec;
        string sol(digits.size(), ' ');
        
        dfs( solVec, 0, sol, digits );
        
        return solVec;
    }
    
    void dfs( vector<string>& solVec, int idx, string& sol, string& digits ) {
        if( idx == digits.size() ) {
            solVec.push_back(sol);
            return;
        }
        
        string letters = getLetters( digits[idx] - '0' );
        for( int i = 0; i < letters.size(); ++i ) {
            sol[idx] = letters[i];
            dfs( solVec, idx+1, sol, digits );
        }
    }
    
    string getLetters( int num ) {
        const string keypad[8] 
            = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return keypad[num-2];
    }
};
