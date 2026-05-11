class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // common interview q, dont let what happened in the coop workshop ever happen again
        // map char to last index found, if previously found, skip forward past it (ONLY IF
        // BEYOND LEFT POINTER OTHERWISE CANT GUARANTEE O(N) COMPLEXITY), 
        if (s.empty() || s.size() == 1) return s.size();

        int left = 0, right = 0;
        unordered_map<char, int> letter_idx;
        int longest = 1;
        while (left <= right && right < s.size()) {

            auto find = letter_idx.find(s[right]);

            if (find == letter_idx.end()) {
                letter_idx[s[right]] = right;
            } else {
              if (find->second >= left) left = find->second + 1;
              find->second = right;  
            }

            longest = max(longest, right - left + 1);
            right++;
        }

        return longest;
    }
};
