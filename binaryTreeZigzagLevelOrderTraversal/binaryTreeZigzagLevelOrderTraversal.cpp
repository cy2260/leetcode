class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if( !root ) return res;
        
        stack<TreeNode*> currStack;
        stack<TreeNode*> nextStack;
        
        currStack.push( root );
        
        bool leftToRight = true;
        
        while( currStack.size() > 0 ) {
            
            vector<int> level;
            while( currStack.size() > 0 ) {
                TreeNode* curr = currStack.top();
                currStack.pop();
                level.push_back( curr->val );
                //if curr level is left to right, push into stack from left to right
                //then in next iteration, node will be accessed from right to left
                if( leftToRight ) {
                    if( curr->left )  nextStack.push( curr->left );
                    if( curr->right ) nextStack.push( curr->right );
                }
                else {
                    if( curr->right ) nextStack.push( curr->right );
                    if( curr->left )  nextStack.push( curr->left );
                }

            }
            res.push_back( level );
            level.clear();
            
            leftToRight = !leftToRight;
            
            swap( currStack, nextStack );
        } 
        return res;
    }
};
