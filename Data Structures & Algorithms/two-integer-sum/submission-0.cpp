class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapped;

        for (int i = 0; i < nums.size(); i++) {
            if (mapped.contains(target - nums[i])) return {mapped[target - nums[i]], i};
            mapped[nums[i]] = i;
        }

        return {};
    }
};
