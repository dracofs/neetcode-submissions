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
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        if (!l1) return l2;
        if (!l2) return l1;
        int carryover = 0, val = 0;

        while (l1 && l2) {
            val = (l1->val + l2->val + carryover) % 10;
            carryover = (l1->val + l2->val + carryover) / 10;
            dummy->next = new ListNode(val);
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            val = (l1->val + carryover) % 10;
            carryover = (l1->val + carryover) / 10;
            dummy->next = new ListNode(val);
            dummy = dummy->next;
            l1 = l1->next;
        }

        while (l2) {
            val = (l2->val + carryover) % 10;
            carryover = (l2->val + carryover) / 10;
            dummy->next = new ListNode(val);
            dummy = dummy->next;
            l2 = l2->next;
        }

        if (carryover) dummy->next = new ListNode(1);

        return head->next;
    }
};
