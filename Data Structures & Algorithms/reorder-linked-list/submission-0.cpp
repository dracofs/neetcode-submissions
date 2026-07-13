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

    void reverse(ListNode*& head) { 
        if (!head || !head->next) return;
        ListNode *prev = 0, *curr = head, *next = curr->next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        return;
    }
    void reorderList(ListNode* head) {
        // reverse latter half (find middle with slow fast ptrs)
        // then intercross till end of 2nd half
        if (!head || !head->next) return;
        ListNode *slow, *fast;
        slow = head, fast = slow;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = slow, *half = slow->next;
        reverse(half);
        mid->next = 0;

        fast = half, slow = head;
        ListNode *nextSlow, *nextFast;
        ListNode *newHead = slow;

        while (fast) {
            nextSlow = slow->next, nextFast = fast->next;
            slow->next = fast;
            fast->next = nextSlow;
            slow = nextSlow;
            fast = nextFast;
        }

        head = newHead;
    }
};
