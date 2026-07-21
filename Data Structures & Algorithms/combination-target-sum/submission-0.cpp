class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, res, curr, target, 0, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int target, int sum, int index) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }

        if (sum > target || index >= nums.size()) {
            return;
        }

        // either use curr element or go next
        curr.push_back(nums[index]);
        backtrack(nums, res, curr, target, sum + nums[index], index);

        // try next element
        curr.pop_back();
        backtrack(nums, res, curr, target, sum, index + 1);
        return;
    }
};
