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
        unordered_map<Node*, Node*> original_new;
        Node *dummy = head;

        while (dummy) {
            Node* newNode = new Node(dummy->val);
            original_new[dummy] = newNode;
            dummy = dummy->next;
        }

        dummy = head;

        while (dummy) {
            original_new[dummy]->next = original_new[dummy->next];
            original_new[dummy]->random = original_new[dummy->random];
            dummy = dummy->next;
        }

        return original_new[head];
    }
};
