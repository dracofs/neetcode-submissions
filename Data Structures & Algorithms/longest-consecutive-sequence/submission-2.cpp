class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0) return 0; 
        unordered_set<int> lookup(nums.begin(), nums.end());
        int longest = 1;
        for (int num : nums) {
            if (lookup.contains(num - 1)) {
                int len  = 1;
                while (lookup.contains(num - 1)) {
                    num--;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
