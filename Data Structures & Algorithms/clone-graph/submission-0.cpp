/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<int, Node*> copy;
        unordered_map<int, bool> visited;
        queue<Node*> q;
        
        q.push(node);
        visited[node->val] = true;

        // init copy step 
        copy[node->val] = new Node(node->val);

        while (!q.empty()) {

            // traversal step
            Node* top = q.front(); q.pop();

            // copy we will be pushing new neighbor nodes to
            Node* copied = copy[top->val];

            for (auto& ne : top->neighbors) {
                
                if (!copy[ne->val]) copy[ne->val] = new Node(ne->val);
                copied->neighbors.push_back(copy[ne->val]);

                if (!visited[ne->val]) { 
                    // traversal step
                    q.push(ne);
                    visited[ne->val] = true; 
                }
            }
        }

        return copy[1];
    }
};
