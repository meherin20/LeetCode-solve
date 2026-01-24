class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        cur = head;
        while (cur) {
            Node* copy = cur->next;
            copy->random = (cur->random) ? cur->random->next : nullptr;
            cur = copy->next;
        }
        Node* newHead = head->next;
        cur = head;

        while (cur) {
            Node* copy = cur->next;
            cur->next = copy->next;                
            copy->next = (copy->next) ? copy->next->next : nullptr; 
            cur = cur->next;
        }

        return newHead;
    }
};
