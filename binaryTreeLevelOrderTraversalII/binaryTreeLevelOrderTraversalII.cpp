class Solution {
public:
    int maxHeight( TreeNode* root ) {
        if( !root ) return 0;
        
        int leftH  = maxHeight( root->left );
        int rightH = maxHeight( root->right );
        
        return max( leftH+1, rightH+1 );
    }
    void printLevel( TreeNode *root, vector<int>& row, int level ) {
        if( !root ) return;
        if( level == 1 ) {
            row.push_back( root->val );
            return;
        }
        printLevel( root->left, row, level-1 );
        printLevel( root->right, row, level-1 );
    }
    
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if( !root ) return res;
        
        int height = maxHeight( root );
        for( int i = height; i >= 1; --i ) {
            vector<int> row;
            printLevel( root, row, i );
            res.push_back( row );
        }
        return res;
    }
};
