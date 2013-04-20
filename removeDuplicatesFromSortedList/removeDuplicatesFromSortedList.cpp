
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if( !head ) return NULL;
        
        ListNode* currNode = head;
        
        while( currNode && currNode->next ) {
            if( currNode->val == currNode->next->val ) {
                ListNode* nextNode = currNode->next;
                currNode->next = nextNode->next;
                delete nextNode;
            }
            else {
                currNode = currNode->next;
            }
        }
        return head;
    }
};
