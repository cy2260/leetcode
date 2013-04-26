
class Solution {
public:
    void flatten(TreeNode *root) {
        if( !root ) return;
        if( !root->left && !root->right ) return;
        
        if( root->left ) {
            TreeNode* temp = root->left;
            while( temp->right ) temp=temp->right;
            temp->right = root->right;
            root->right = root->left;
            root->left  = NULL;
        }
        flatten( root->right );
    }
};
