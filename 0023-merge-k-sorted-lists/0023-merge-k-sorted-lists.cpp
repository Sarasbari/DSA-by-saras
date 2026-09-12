/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minheap;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr)
                minheap.push(lists[i]);
        }

        ListNode dummy(0);
        ListNode* current = &dummy;

        while (!minheap.empty()) {
            ListNode* smallest = minheap.top();
            minheap.pop();

            current->next = smallest;
            current = current->next;

            if (smallest->next != nullptr)
                minheap.push(smallest->next);
        }
        return dummy.next;
    }
};