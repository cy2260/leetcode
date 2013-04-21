
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if( !head || !head->next ) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* currNode = dummy;
        
        while( currNode->next ) {
            bool hasDup = false;
            ListNode* nextNode = currNode->next;
            while( nextNode->next && nextNode->val == nextNode->next->val ) {
                hasDup = true;
                ListNode* del = nextNode;
                nextNode = nextNode->next;
                delete del;
            }
            if( hasDup ) {
                currNode->next = nextNode->next;
                delete nextNode;
            }
            else {
                currNode = currNode->next;
            }
        }
        
        currNode = dummy->next;
        delete dummy;
        return currNode;
    }
};
