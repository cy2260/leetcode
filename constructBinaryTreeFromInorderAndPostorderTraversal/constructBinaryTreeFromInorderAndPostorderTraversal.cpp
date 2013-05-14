class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if( inorder.size() < 1 ) return NULL;
        unordered_map<int, int> idxMap;
        for( int i = 0; i < inorder.size(); ++i ) idxMap[inorder[i]] = i;
        int low  = 0;
        int high = inorder.size() - 1;
        
        return build( inorder, postorder, idxMap, low, high );
    }
    
    TreeNode* 
    build( vector<int> &inorder, vector<int> &postorder, unordered_map<int, int>& idxMap, int low, int high ) {
        if( low > high ) return NULL;
        
        int inIdx = idxMap[postorder.back()];
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();
        root->right = build( inorder, postorder, idxMap, inIdx+1, high );
        root->left  = build( inorder, postorder, idxMap, low , inIdx-1 );
        
        return root;
    }
};
