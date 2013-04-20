struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct NodeComparison {
    bool operator() ( const ListNode* a, const ListNode* b) {
        return (a->val > b->val);
    }    
};

class Solution {
public:
    typedef priority_queue<ListNode*, vector<ListNode*>, NodeComparison> MinHeap;
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if( lists.size() < 1 ) return NULL;
        
        MinHeap minHeap;
        for( int i = 0; i < lists.size(); ++i ) {
            if( lists[i] != NULL ) minHeap.push( lists[i] );
        }
        
        if( minHeap.size() == 0 ) return NULL;
        
        ListNode* head = minHeap.top();
        ListNode* curr = head;
        minHeap.pop();
        
        while( minHeap.size() ) {
            if( curr->next ) minHeap.push(curr->next);
            curr->next = minHeap.top();
            curr = curr->next;
            minHeap.pop();
        }
        
        return head;
    }
};


class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if( lists.size() < 1 ) return NULL;
        
        ListNode* head = lists[0];
        
        for( int i = 1; i < lists.size(); ++i ) {
            head = mergeTwoLists( head, lists[i] );
        }
        
        return head;
    }
    
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
