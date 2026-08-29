class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        backtrack(nums, 0, {});
        return res;
    }

    void backtrack(const vector<int>& nums, int index, vector<int> curr) {
        if (index >= nums.size()) {
            res.push_back(curr);
            return;
        }

        // we can either pick an element
        curr.push_back(nums[index]);
        backtrack(nums, index + 1, curr);

        // or skip it
        curr.pop_back();
        while (index < nums.size() - 1 && nums[index] == nums[index + 1]) index++;
        backtrack(nums, index + 1, curr);
        return;
    }
};
