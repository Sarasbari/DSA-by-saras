class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        // 1. Create copy beside every original node
        Node* curr = head;

        while (curr != nullptr) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // 2. Set random pointers of copied nodes
        curr = head;

        while (curr != nullptr) {
            if (curr->random != nullptr)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // 3. Separate original and copied lists
        Node* copyHead = head->next;
        Node* copy = copyHead;
        curr = head;

        while (curr != nullptr) {
            curr->next = curr->next->next;

            if (copy->next != nullptr)
                copy->next = copy->next->next;

            curr = curr->next;
            copy = copy->next;
        }

        return copyHead;
    }
};