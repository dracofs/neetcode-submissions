/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> n;

        Node* dummy = head;

        while (dummy) {
            n[dummy] = new Node(dummy->val);
            dummy = dummy->next;
        }

        dummy = head;
        Node* res = n[dummy];
        while (dummy) {
            n[dummy]->next = n[dummy->next];
            n[dummy]->random = n[dummy->random];
            dummy = dummy->next;
        }
        return res;

    }
};
