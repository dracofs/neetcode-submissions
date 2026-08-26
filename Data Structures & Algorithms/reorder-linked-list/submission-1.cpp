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
        if (!head) return;
        ListNode* prev = 0;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* half = slow->next;
        slow->next = 0;
        reverse(half);

        ListNode* dummy = head;
      
        ListNode* middle = half;
        ListNode* redo = head;

        while (middle) {
            ListNode* rnext = redo->next;
            ListNode* mnext = middle->next;
            redo->next = middle;
            redo = rnext;
            middle->next = redo;
            middle = mnext;
        }
    }
};
