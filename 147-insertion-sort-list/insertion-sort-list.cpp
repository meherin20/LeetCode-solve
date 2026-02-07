class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0); // dummy head for sorted list
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // store next node

            // find correct position in sorted list
            ListNode* prev = dummy;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // insert curr after prev
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode; // move forward
        }

        return dummy->next;
    }
};
