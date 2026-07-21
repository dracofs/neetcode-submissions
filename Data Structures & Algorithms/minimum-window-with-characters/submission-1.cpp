class Solution {
public:
    string minWindow(string s, string t) {

        string res = "";
        int len = INT_MAX;

        unordered_map<char, int> countT;
        for (char c : t) countT[c]++;

        unordered_map<char, int> countS;
        int met = 0;
        int need = countT.size();

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            countS[s[r]]++;
            if (countT[s[r]] > 0 && countS[s[r]] == countT[s[r]]) met++;
            while (met == need) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    res = s.substr(l, r - l + 1);
                }
                countS[s[l]]--;
                if (countT[s[l]] > 0 && countS[s[l]] < countT[s[l]]) met--;
                l++;
            }
        }

        if (len == INT_MAX) return "";
        return res;
    }
};
