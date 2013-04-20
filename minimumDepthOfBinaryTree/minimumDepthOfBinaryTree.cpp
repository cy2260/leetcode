class Solution {
public:
    int minDepth(TreeNode *root) {
        if( !root ) return 0;
        
        int leftDepth  = minDepth( root->left );
        int rightDepth = minDepth( root->right );
        
        if( leftDepth == 0 && rightDepth == 0 ) return 1;
        
        if( leftDepth  == 0 ) leftDepth  = INT_MAX;
        if( rightDepth == 0 ) rightDepth = INT_MAX;
        
        return min(leftDepth, rightDepth) + 1;
    }
};

