
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if( num.size() < 1 ) return NULL;
        
        TreeNode* root = toBST( num, 0, num.size()-1 );
        
        return root;
    }
    
    TreeNode* toBST( vector<int> &num, int low, int high ) {
        if( low > high ) return NULL;
        
        int mid = low + (high-low)/2;
        
        TreeNode* root = new TreeNode( num[mid] );
        root->left  = toBST( num, low, mid-1 );
        root->right = toBST( num, mid+1, high );
        
        return root;
    }
};
