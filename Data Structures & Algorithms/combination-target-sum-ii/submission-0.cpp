class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        gen(candidates, res, curr, target, 0, 0);
        return res;
    }

    void gen(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int target, int sum, int idx) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }

        if (sum > target || idx >= nums.size()) return;

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i - 1] == nums[i]) continue;
            curr.push_back(nums[i]);
            gen(nums, res, curr, target, sum + nums[i], i + 1);
            curr.pop_back();
        }     
        return;
    }
};
