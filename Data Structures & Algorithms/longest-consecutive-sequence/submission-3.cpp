class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup (nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (!lookup.contains(num - 1)) {
                int len = 1;
                while (lookup.contains(num + 1)) {
                    num++;
                    len++;
                }
                
                longest = max(longest, len);
            }
        }

        return longest;
    }
};
