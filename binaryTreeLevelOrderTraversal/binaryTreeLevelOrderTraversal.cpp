class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if( !root ) return res;
        
        queue<TreeNode*> q;
        q.push( root );
        q.push( NULL );
        
        while( q.size() > 0 ) {
            TreeNode* curr = q.front();
            vector<int> level;
            while( curr ) {
                q.pop();
                level.push_back( curr->val );
                if( curr->left )  q.push( curr->left );
                if( curr->right ) q.push( curr->right );
                curr = q.front();
            }
            res.push_back( level );
            level.clear();
            
            q.pop(); //pop the NULL
            
            //finish current level, if q is empty, then no more level
            if( q.size() > 0 ) q.push( NULL );
        }
        
        return res;
    }
};
