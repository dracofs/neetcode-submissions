class Solution {
public:
    bool isAnagram(string s, string t) {
        // O(26) 0 -> 'a' 25 -> 'z'
        vector<int> str1(26, 0);
        vector<int> str2(26, 0);

        for (const char& c: s) {
            str1[c - 'a']++;
        }

        for (const char& c : t) {
            str2[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (str1[i] != str2[i]) {
                return false;
            }
        }
        return true;
    }
};
