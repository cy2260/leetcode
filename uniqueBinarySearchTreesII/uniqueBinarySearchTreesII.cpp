
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        
        return genTrees( 1, n );
    }
    
    vector<TreeNode*> genTrees( int start, int end ) {
        vector<TreeNode*> res;
        if( start > end ) {
            res.push_back(NULL);
            return res;
        }
        
        for( int i = start; i <= end; ++i ) {
            vector<TreeNode*> leftSubtrees  = genTrees( start, i-1 );
            vector<TreeNode*> rightSubtrees = genTrees( i+1, end );
            for( int j = 0; j < leftSubtrees.size(); ++j ) {
                for( int k = 0; k < rightSubtrees.size(); ++k ) {
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftSubtrees[j];
                    root->right = rightSubtrees[k];
                    res.push_back( root );
                }
            }
        }
        
        return res;
    }
};
