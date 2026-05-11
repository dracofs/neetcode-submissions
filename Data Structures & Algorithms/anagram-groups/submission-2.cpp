class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freqToWord;
        
        string currFreq;

        for (string str : strs) {
            currFreq = ""; 
            vector<int> charFreq(26);

            for (char c : str) {
                charFreq[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                
                currFreq += (i + 'a') + charFreq[i];
            }

            freqToWord[currFreq].push_back(str);
        }

        vector<vector<string>> ans;

        for (const pair<string, vector<string>> p : freqToWord) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
