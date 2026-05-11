class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26);
        int sLen = s.size();
        int tLen = t.size();

        if (sLen != tLen) return false;

        for (int i = 0; i < sLen; ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int freq : count) {
            if (freq != 0) return false;
        }

        return true;
    }
};
