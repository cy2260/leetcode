
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if( !l1 ) return l2;
        if( !l2 ) return l1;
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while( l1 && l2 ) {
            if( l1->val < l2->val ) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if( l1 ) curr->next = l1;
        if( l2 ) curr->next = l2;
        
        curr = head->next;
        delete head;
        
        return curr;
    }
};

