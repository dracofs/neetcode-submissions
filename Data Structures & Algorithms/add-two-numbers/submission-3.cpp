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
        int carryover = 0;
        int val = 0;
        ListNode* senti = new ListNode(0);
        ListNode* dum = senti;
        while (l1 && l2) {
            int raw = l1->val + l2->val + carryover;
            val = raw % 10;
            carryover = raw / 10;
            
            dum->next = new ListNode(val);
            dum = dum->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int raw = l1->val + carryover;
            val = raw % 10;
            carryover = raw / 10;
            dum->next = new ListNode(val);
            dum = dum->next;
            l1 = l1->next;
        }

        while (l2) {
            int raw = l2->val + carryover;
            val = raw % 10;
            carryover = raw / 10;
            dum->next = new ListNode(val);
            dum = dum->next;
            l2 = l2->next;
        }

        if (carryover) {
            dum->next = new ListNode(1);
        }

        return senti->next;
    }
};
