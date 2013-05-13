class Solution {
public:
    void connect(TreeLinkNode *root) {
        if( !root ) return;
        if( !root->left && !root->right ) return;
        
        if( root->left ) {
            root->left->next = root->right;
        }
        if( root->right ) {
            root->right->next = root->next ? root->next->left : NULL;
        }
        connect( root->left );
        connect( root->right );
    }
};
