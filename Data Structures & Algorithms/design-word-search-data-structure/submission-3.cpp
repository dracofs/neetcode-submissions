class TrieNode {
    public:
        vector<TrieNode*> next;
        char c;
        bool word;
        TrieNode(char _c) {
            next.resize(26, nullptr);
            c = _c;
            word = false;
        }
};

class WordDictionary {
public:
    TrieNode* head;
    WordDictionary() { 
        head = new TrieNode(' ');
    }
    void addWord(string word) {
        TrieNode* curr = head;
        for (char c : word) {
            if (curr->next[c - 'a']) curr = curr->next[c - 'a'];
            else {
                curr->next[c - 'a'] = new TrieNode(c);
                curr = curr->next[c - 'a'];
            }
        }
        curr->word = true;
        return;   
    }
    
    bool search(string word) {
        return helper(word, 0, head);
    }

    bool helper(string word, int index, TrieNode* head) {
        if (index == word.size()) { 
            if (head->word) return true;
            return false;
        } 

        for (TrieNode* n : head->next) {
            if (!n) continue;

            // cout << "Processing char: " << word[index] << " at index: " << index << endl;
            if (word[index] == '.') {
                if (helper(word, index + 1, n)) return true;
                else continue;
            } 

            if (word[index] == n->c) {
                return helper(word, index + 1, n);
            }
        }

        return false;
    }
};
