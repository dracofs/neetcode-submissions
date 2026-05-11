class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        vector<vector<string>> res;
        
        for (const string& str : strs) {
            vector<int> charCount(26);

            for (char c : str) {
                charCount[c - 'a']++;
            }

            string res = "";
            for (int i = 0; i < 26; i++) {
                res += (i + 'a') + charCount[i];
            }

            buckets[res].push_back(str);
        }

        for (const auto& [key, val] : buckets) {
            res.push_back(val);
        }

        return res;
    }
};
