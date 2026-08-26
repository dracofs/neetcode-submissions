class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

		int longest = 1;
		unordered_set<int> lookup(nums.begin(), nums.end());

		for (int num : nums) {
			if (!lookup.contains(num - 1)) {
				// num is the start of a seq
				int len = 0;
				while (lookup.contains(num)) { len++; num++; }
				longest = max(longest, len);
			}
		}

		return longest;
    }
};
