
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if( !head ) return NULL;
        int len = 1;
        ListNode* cur = head;
        while( cur = cur->next ) ++len;
        return toBST( head, 0, len-1 );
    }
    
    TreeNode* toBST( ListNode* &head, int start, int end ) {
        if( start > end ) return NULL;
        
        int mid = start + ( end - start )/2;
        TreeNode* leftNode = toBST( head, start, mid-1 );
        TreeNode* rootNode = new TreeNode( head->val );
        head = head->next;
        TreeNode* rightNode = toBST( head, mid+1, end );
        
        rootNode->left  = leftNode;
        rootNode->right = rightNode;
        
        return rootNode;
    } 
};
