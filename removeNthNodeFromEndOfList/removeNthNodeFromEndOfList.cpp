class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if( !head || n < 1 ) return NULL;
        
        ListNode* currNode = head;
        while( currNode && n > 0 ) {
            currNode = currNode->next;
            --n;
        }
        //if currNode is NULL, it means n = length of the list, head node needs to be deleted
        if( !currNode ) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        
        ListNode* lastNode = currNode;
        currNode = head;
        //find the n+1TH node from the end of the list
        while( lastNode && lastNode->next ) {
            lastNode = lastNode->next;
            currNode = currNode->next;
        }
        
        ListNode* tmp = currNode->next;
        currNode->next = tmp->next;
        delete tmp;
        return head;
    }
};
