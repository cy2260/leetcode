
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> pathVec;
        vector<int> path;
        if( !root ) return pathVec;
        
        findPaths( path, pathVec, root, sum );
        
        return pathVec;
    }
    
    void findPaths( vector<int>& path, vector<vector<int>>& pathVec, TreeNode* root, int sum ) {
        path.push_back( root->val );
        if( !root->left && !root->right ) {
            if( root->val == sum ) pathVec.push_back( path );
        }
        else {
            sum -= root->val;
            if( root->left  ) findPaths( path, pathVec, root->left, sum );    
            if( root->right ) findPaths( path, pathVec, root->right, sum );
        }
        path.pop_back();
        return;
    }
};
