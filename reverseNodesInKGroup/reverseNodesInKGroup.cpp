class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if( !head ) return NULL;
        if( k < 2 ) return head;
        
        int count = k;
        ListNode* currNode = head;
        while( k > 0 && currNode ) {
            currNode = currNode->next;
            --k;
        }
        
        if( k > 0 ) return head;
        else {
            ListNode* tailNode = reverseKGroup( currNode, count );
            ListNode* currNode = head;
            while( count > 0 ) {
                ListNode* nextNode = currNode->next;
                currNode->next     = tailNode;
                tailNode           = currNode;
                head               = currNode;
                currNode           = nextNode;
                --count;
            }
            return head;
        }
        
    }
};
