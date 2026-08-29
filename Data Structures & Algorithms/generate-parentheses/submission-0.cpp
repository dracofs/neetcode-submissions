class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return res;
    }

    void backtrack(string curr, int open, int closed, int n) {
        if (closed > open || open > n || closed > n) return;

        if (closed == open && open == n) {
            res.push_back(curr);
            return;
        }

        // either append a '(' or ')'
        curr.push_back('(');
        backtrack(curr, open + 1, closed, n);

        curr.pop_back();
        curr.push_back(')');
        backtrack(curr, open, closed + 1, n);
        return;
    }
};
