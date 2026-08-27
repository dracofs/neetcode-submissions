class Node {
    public:
        int key_;
        int val_;
        Node* next_;
        Node* prev_;
        Node(int key, int val) {
            key_ = key;
            val_ = val;
            next_ = 0;
            prev_ = 0;
        }
};

class LRUCache {
public:
    int capacity_;
    int size_;
    unordered_map<int, Node*> nmap;
    Node* shead_;
    Node* stail_;
    LRUCache(int capacity) {
        capacity_ = capacity;
        size_ = 0;
        shead_ = new Node(-1, -1);
        stail_ = new Node(-1, -1);
        shead_->next_ = stail_;
        stail_->prev_ = shead_;
    }
    
    void remove(Node* n) {
        n->prev_->next_ = n->next_;
        n->next_->prev_ = n->prev_;
    }

    void insert(Node* n) {
        Node* temp = stail_->prev_;
        stail_->prev_ = n;
        n->next_ = stail_;
        temp->next_ = n;
        n->prev_ = temp;
    }

    int get(int key) {
        if (!nmap[key]) return -1;
        remove(nmap[key]);
        insert(nmap[key]);
        return nmap[key]->val_;
    }
    
    void put(int key, int value) {
        if (nmap[key]) {
            remove(nmap[key]);
        } else size_++;

        if (size_ > capacity_) {
            Node* removed = shead_->next_;
            remove(removed);
            nmap[removed->key_] = 0;
            size_--;
        }

        Node* new_node = new Node(key, value);
        insert(new_node);
        nmap[key] = new_node;
    }
};
