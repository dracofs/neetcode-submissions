class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        std::string res = "";
        for (int i = 0; i < strs.size(); i++) {
            res += to_string(strs[i].size()) + "@" + strs[i]; 
        }
        return res;
    }

    vector<string> decode(string s) {
        std::vector<string> res;
        // ptr -> i, prev -> j
        int ptr = 0;
        int prev;
        while (ptr < s.size()) {
            prev = ptr;
            while (s[ptr] != '@') { ptr++; }
            int size = stoi(s.substr(prev, ptr - prev));
            res.push_back(s.substr(ptr + 1, size));
            ptr += size + 1;
        }
        return res;
    }
};
