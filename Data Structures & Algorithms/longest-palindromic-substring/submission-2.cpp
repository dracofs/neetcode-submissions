class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int) s.size();
        string longest = "";
        for (int i = 0; i < n; i++) {
            // treat each index as a possible centre for a palindrome
            
            // even palin
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if ((r - l + 1) > longest.size()) longest = s.substr(l, r - l + 1);
                l--, r++;
            }

            // odd palin
            l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if ((r - l + 1) > longest.size()) longest = s.substr(l, r - l + 1);
                l--, r++;
            }
        }

        return longest;
    }
};
