class Node {
public:
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int k, int v) {
        key = k;
        val = v;
        next = 0;
        prev = 0;
    }
};

class LRUCache {
public:
    int smax;
    int size;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> key_node;
    LRUCache(int capacity) {
        smax = capacity;
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        Node *curr = key_node[key];
        if (!curr) return -1;

        // disconect prior and next nodes
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        // reattach at end
        tail->prev->next = curr;
        curr->prev = tail->prev;
        curr->next = tail;
        tail->prev = curr;
        return curr->val;
    }
    
    void put(int key, int value) 
    {   

        Node* new_node = new Node(key, value);
        Node* old = key_node[key];
        key_node[key] = new_node;

        // remove node if previously existed
        if (old) {
            old->prev->next = old->next;
            old->next->prev = old->prev;
            delete(old);
        } else size++;

        // if over capacity, remove head node
        if (size > smax) {
            Node *remove = head->next;
            key_node[remove->key] = 0;
            remove->prev->next = remove->next;
            remove->next->prev = remove->prev;
            delete(remove);
            --size;
        }

        // reattach new one at end
        tail->prev->next = new_node;
        new_node->prev = tail->prev;
        new_node->next = tail;
        tail->prev = new_node;
        return;
    }
};
