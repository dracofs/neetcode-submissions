class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        unordered_map<char, char> mmap = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };
        for (char c : str) {
            if (!mmap.contains(c)) s.push(c);
            else {
                if (s.empty() || mmap[c] != s.top()) return false;
                s.pop();
            }
        }
        return s.empty();
    }
};
