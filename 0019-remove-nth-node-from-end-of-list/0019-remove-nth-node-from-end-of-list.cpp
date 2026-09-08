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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next)
            return NULL;
        ListNode* temp = head;
        int cnt = 0;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int res = cnt - n;
        if (res == 0)
            return head->next;

        for (int i = 0; i < res - 1; i++) {
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete (delNode);
        return head;
    }
};