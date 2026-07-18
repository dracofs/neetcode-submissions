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

    ListNode* reverse(ListNode* head, int count) 
    {
        if (!head || !head->next) return head;

        ListNode *prev, *curr;
        prev = 0; curr = head;
        ListNode *next;
        while (count-- && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // current head, tail, next group head, next group tail
        ListNode *prev, *curr, *rev, *next;
        prev = 0; curr = head; rev = 0; next = head;

        if (!head || !head->next) return head;

        ListNode* res = head;
        int copy = k;
        while (--copy && res) res = res->next;
        if (!res) return head;

        while (true) {
            
            // reverse current group, attach prev to rev,
            // attach tail (curr) to next, update pointers:
            // rev <- curr, curr <- next, next = curr->next (k times),
            // rev = reverse(curr),  

            // initiate next;
            if (next) cout << next->val << endl;
            copy = k;
            while (copy-- && next) next = next->next;
            if ((copy > 0) || (copy == 0 && !next)) break;

            rev = reverse(curr, k);
            if (prev) prev->next = rev;
            curr->next = next;
            
            prev = curr;
            curr = next;
        }

        return res;
    }
};
