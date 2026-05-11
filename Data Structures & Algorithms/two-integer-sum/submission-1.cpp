class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_idx;

        for (int i = 0; i < nums.size(); i++) {
            int lookup = target - nums[i];

            if (val_idx.find(lookup) != val_idx.end()) {
                return {val_idx.find(lookup)->second, i};
            }

            val_idx[nums[i]] = i;
        }

        return {};
    }
};
