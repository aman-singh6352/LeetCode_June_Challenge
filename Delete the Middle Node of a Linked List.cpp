class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            if(head->next == NULL) return NULL;
            ListNode* slow = head, *fast = head, *prev;
            while(fast != NULL && fast->next != NULL){
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            // slow will be pointing to the middle node, so we need to delete it
            prev->next = slow->next;
            return head;
        }
    };