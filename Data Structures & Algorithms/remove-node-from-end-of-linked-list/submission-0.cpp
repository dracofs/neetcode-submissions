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
        if (!head) return head;

        ListNode *slow = head, *fast = slow;
        ListNode *prev = 0;
    
        while (--n) {
            fast = fast->next;
        }
        
        while (fast->next) {
            prev = slow;

            slow = slow->next;
            fast = fast->next;

        }

        if (!prev) return head->next;
        if (!slow) {
            prev = 0; 
            return head;
        }
        prev->next = slow->next;
        slow->next = 0;

        return head;
    }
};
