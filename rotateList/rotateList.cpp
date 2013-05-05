class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if( !head || k < 0 ) return NULL;

        int len = 1;
        ListNode* currNode = head;
        //count length and find the last node
        while( currNode && currNode->next ) {
            ++len;
            currNode = currNode->next;
        }
        
        currNode->next = head; //cycly the list
        
        k = len - k%len;
        
        while( k > 0 ) {
            currNode = currNode->next;
            --k;
        }
        
        head = currNode->next;
        currNode->next = NULL;
        
        return head;   
    }
};
