class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if( !head || m > n ) return NULL;
        
        ListNode* currNode = head;
        ListNode* prevNode = NULL;
        while( currNode && m > 1 ) {
            prevNode = currNode;
            currNode = currNode->next;
            --m;--n;
        }
        
        int k = n-m;
        
        while( k ) {
            ListNode* nextNode = currNode->next;
            if( !nextNode ) break;
            
            if( !prevNode ) {
                currNode->next = nextNode->next;
                nextNode->next = head;
                head = nextNode;
            }
            else {
                currNode->next = nextNode->next;
                nextNode->next = prevNode->next;
                prevNode->next = nextNode;
 
            }
            --k;
        }
        
        return head;
    }
};
