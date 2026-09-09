class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> seen(wordDict.begin(), wordDict.end());
        vector<bool> memo(s.size(), true);
        return gen(s, 0, seen, memo);
    }

    bool gen(string s, int start, unordered_set<string>& seen, vector<bool>& memo) {
        if (start == s.size()) return true;
        if (!memo[start]) return false;

        for (int i = start + 1; i <= s.size(); i++) {
            string curr = s.substr(start, i - start);
            if (seen.contains(curr)) {
                if (gen(s, i, seen, memo)) return true;
                memo[start] = true;
            }
        }

        memo[start] = false;
        return false;
    }
};
