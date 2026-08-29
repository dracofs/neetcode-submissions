class Solution {
public:
    unordered_map<int, vector<char>> phone = {
        {2, {'a', 'b', 'c'}},
        {3, {'d', 'e', 'f'}},
        {4, {'g', 'h', 'i'}},
        {5, {'j', 'k', 'l'}},
        {6, {'m', 'n', 'o'}},
        {7, {'p', 'q', 'r', 's'}},
        {8, {'t', 'u', 'v'}},
        {9, {'w', 'x', 'y', 'z'}}
    };

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> res;
        generate(res, digits, 0, "");    
        return res;
    }

    void generate(vector<string>& res, string digits, int index, string curr) {
        if (index >= digits.size()) {
            res.push_back(curr);
            return;
        }

        for (char c : phone[digits[index] - '0']) {
            // we can only use ONE, so we have the options
            // 1. use the current one, 2. skip and use a latter one
            // suppose we take the current one, 
            curr.push_back(c);
            generate(res, digits, index + 1, curr);
            curr.pop_back();
        }

        return;
    }
};

