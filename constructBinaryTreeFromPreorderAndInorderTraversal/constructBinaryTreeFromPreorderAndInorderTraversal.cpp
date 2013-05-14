class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if( inorder.size() < 1 ) return NULL;
        unordered_map<int, int> idxMap;
        for( int i = 0; i < inorder.size(); ++i ) idxMap[inorder[i]] = i;
        int low  = 0;
        int high = inorder.size() - 1;
        std::reverse( preorder.begin(), preorder.end());
        return build( inorder, preorder, idxMap, low, high );
    }
    
    TreeNode* 
    build( vector<int> &inorder, vector<int> &preorder, unordered_map<int, int>& idxMap, int low, int high ) {
        if( low > high ) return NULL;
        
        int inIdx = idxMap[preorder.back()];
        TreeNode* root = new TreeNode(preorder.back());
        preorder.pop_back();
        root->left  = build( inorder, preorder, idxMap, low , inIdx-1 );
        root->right = build( inorder, preorder, idxMap, inIdx+1, high );
        
        return root;
    }
};
