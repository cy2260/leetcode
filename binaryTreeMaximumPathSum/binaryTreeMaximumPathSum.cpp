
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if( !root ) return 0;
        
        int maxSoFar = INT_MIN;
        maxPath( root, maxSoFar );
        return maxSoFar;
    }
    
    int maxPath( TreeNode *root, int& maxSoFar ) {
        if( !root ) return 0;
        
        int leftMax  = maxPath( root->left, maxSoFar );
        int rightMax = maxPath( root->right, maxSoFar );
        
        //get max path sum as current node is root
        int sum = root->val;
        if( leftMax > 0  ) sum += leftMax;
        if( rightMax > 0 ) sum += rightMax;
        
        maxSoFar = max( maxSoFar, sum );
        
        int val = root->val;
        
        //return max path from current node to its parent
        return max( val, val+max(leftMax, rightMax) );
    }  
};
