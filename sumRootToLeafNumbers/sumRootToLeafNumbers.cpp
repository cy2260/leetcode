
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if( !root ) return 0;
        
        return sumNums( root, 0 );
        
    }
    
    int sumNums( TreeNode* root, int sum ) {
        if( !root ) return 0;
        
        sum = sum*10 + root->val;
        if( !root->left && !root->right ) return sum;
        
        int leftSum  = sumNums( root->left, sum );
        int rightSum = sumNums( root->right, sum );
        
        return (leftSum + rightSum);
    }
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if( !root ) return 0;
        
        int sum = 0;
        int res = 0;
        sumNums( root, sum, res );
        
        return res;
    }
    
    void sumNums( TreeNode* root, int sum, int& res ) {
        if( !root ) return;
        
        sum = sum*10 + root->val;
        if( !root->left && !root->right ) {
            res += sum;
            return;
        }
        
        sumNums( root->left, sum, res );
        sumNums( root->right, sum, res );
    }
};

