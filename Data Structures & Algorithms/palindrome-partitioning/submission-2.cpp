class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        gen(s, {}, 0);
        return res;
    }

    bool isPalin(string s) {
        if (s.empty()) return false;

        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }

    void gen(string& s, vector<string> curr, int index) {
        if (index == s.size()) {
            if (!curr.empty()) res.push_back(curr);
        }

        for (int i = index; i < s.size(); i++) {

            // if palindrome, we split
            string scurr = s.substr(index, i - index + 1);
            if (isPalin(scurr)) {
                curr.push_back(scurr);
                gen(s, curr, i + 1);
                curr.pop_back();
            }

            // either way, we can always extend
            // in this case, we do nothing, as the loop takes care of it
        }
        return;
    }
};
