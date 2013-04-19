
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if( !root ) return true;
        
        return checkIsSymmetric( root->left, root->right );
    }
    
    bool checkIsSymmetric( TreeNode* nodeA, TreeNode* nodeB ) {
        if( !nodeA || !nodeB ) return (!nodeA && !nodeB);
        
        if( nodeA->val != nodeB->val ) return false;
        
        return checkIsSymmetric( nodeA->left, nodeB->right )
                && checkIsSymmetric( nodeA->right, nodeB->left );
    }
};
