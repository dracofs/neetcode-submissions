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

    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        priority_queue<ListNode*, vector<ListNode*>, comp> heap;

        for (ListNode* list : lists) {
            if (list) heap.push(list);
        }

        while (!heap.empty()) {
            ListNode* top = heap.top();
            heap.pop();
            dummy->next = top;
            dummy = dummy->next;
            if (top->next) heap.push(top->next);
        }

        return head->next;
    }
};
