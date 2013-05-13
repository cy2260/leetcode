class Solution {
public:
    void connect(TreeLinkNode *root) {
        if( !root ) return;
        if( !root->left && !root->right ) return;
        
        if( root->left ) {
            if( root->right ) root->left->next = root->right;
            else              root->left->next = getNext( root->next );
        }
        if( root->right ) {
            root->right->next = getNext( root->next );
        }
        connect( root->right );
        connect( root->left );
    }
    
    TreeLinkNode* getNext( TreeLinkNode* nextNode ) {
        if( !nextNode ) return NULL;
        
        while( nextNode && !nextNode->left && !nextNode->right )
            nextNode = nextNode->next;
            
        if( !nextNode ) return NULL;
        else            return nextNode->left ? nextNode->left : nextNode->right;
    }
};
