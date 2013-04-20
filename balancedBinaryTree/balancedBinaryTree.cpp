
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if( !root ) return true;
        
        int height = 0;
        return isBalancedTree( root, &height );
    }
    
    bool isBalancedTree( TreeNode* root, int* height ) {
        if( !root ) return true;
        
        int leftHeight  = 0;
        int rightHeight = 0;
        
        bool isLeftBalanced  = isBalancedTree( root->left, &leftHeight );
        bool isRightBalanced = isBalancedTree( root->right, &rightHeight );
        
        *height = 1 + max( leftHeight, rightHeight );
        
        return isLeftBalanced && isRightBalanced && ( abs(leftHeight-rightHeight) <= 1 );
    } 
};
