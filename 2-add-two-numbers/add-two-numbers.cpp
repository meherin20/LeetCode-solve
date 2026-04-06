/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify result list creation
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;

        // Traverse both lists
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;

            // Add l1 value if exists
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add l2 value if exists
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Update carry
            carry = sum / 10;

            // Create new node with digit
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        // Return result (skip dummy node)
        return dummy->next;
    }
};