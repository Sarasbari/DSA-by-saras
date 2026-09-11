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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;

        ListNode* prev = nullptr;
        int carry = 0, sum;
        ListNode* result = l1;

        while (l1 && l2) {
            sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            if (prev) {
                prev->next = l1;
                prev = prev->next;
            } else
                prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            sum = l1->val + carry;

            l1->val = sum % 10;
            carry = sum / 10;

            prev->next = l1;
            prev = prev->next;

            l1 = l1->next;
        }
        while (l2) {
            sum = l2->val + carry;

            l2->val = sum % 10;
            carry = sum / 10;

            prev->next = l2;
            prev = prev->next;

            l2 = l2->next;
        }

        if (carry)
            prev->next = new ListNode(carry);
        return result;
    }
};