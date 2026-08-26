class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> buckets;

        for (string s : strs) {
            string norm = "";
            vector<int> count(26);

            for (char c : s) {
                count[c - 'a']++;
            }

            for (int i{0}; i < 26; i++) {
                norm.push_back(i + 'a');
                norm.push_back(count[i]);
            }

            buckets[norm].push_back(s);
        }

        for (const auto& [_, words] : buckets) {
            vector<string> curr;

            for (string word : words) {
                curr.push_back(word);
            }

            res.push_back(curr);
        }

        return res;
    }
};
