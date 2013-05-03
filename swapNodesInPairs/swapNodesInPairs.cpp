class Solution {
public:
    ListNode *swapNodes( ListNode* a, ListNode* b ) {
        a->next = b->next;
        b->next = a;
        return b;
    }
    
    ListNode *swapPairs(ListNode *head) {
        if( !head )       return NULL;
        if( !head->next ) return head;

        ListNode* currNode = head;
        ListNode* nextNode = head->next;
        
        head = swapNodes( currNode, nextNode );
        currNode->next = swapPairs( currNode->next );
        
        return head;
    }
};

class Solution {
public:
    ListNode *swapNodes( ListNode* a, ListNode* b ) {
        a->next = b->next;
        b->next = a;
        return b;
        
    }
    
    ListNode *swapPairs(ListNode *head) {
        if( !head )       return NULL;
        if( !head->next ) return head;

        ListNode* currNode = head;
        ListNode* prevNode = NULL;
        
        while( currNode ) {
            ListNode* nextNode = currNode->next;
            if( !nextNode ) break;
            ListNode* tempNode = swapNodes( currNode, nextNode );
            if( prevNode == NULL )  head = tempNode;
            else                    prevNode->next = tempNode;
            prevNode = currNode;
            currNode = currNode->next;
            
        }
        
        return head;
    }
};

