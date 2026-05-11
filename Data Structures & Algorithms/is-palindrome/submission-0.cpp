class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while (start <= end) {

            while (start < s.size() && !isalnum(s[start])) start++;
            while (end >= 0 && !isalnum(s[end])) end--;

            if (start > end) break;
            if (std::tolower(s[start]) != std::tolower(s[end])) return false;
            start++;
            end--;
        }   

        return true;
    }
};
 