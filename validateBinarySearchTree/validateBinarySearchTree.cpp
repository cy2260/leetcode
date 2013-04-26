class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if( !root ) return true;
        
        return isBST( root, INT_MIN, INT_MAX );
    }
    
    bool isBST( TreeNode* root, int minVal, int maxVal ) {
        if( !root ) return true;
        
        if( root->val <= minVal || root->val >= maxVal ) return false;
        
        return isBST( root->left, minVal, root->val ) && isBST( root->right, root->val, maxVal );
    }
};

