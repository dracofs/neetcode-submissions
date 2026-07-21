class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        gen(nums, res, curr, 0);
        return res;
    }

    void gen(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, int idx) {
        if (idx >= nums.size()) {
            res.push_back(curr);
            return;
        }

        // either include num or dont
        curr.push_back(nums[idx]);
        gen(nums, res, curr, idx + 1);
        curr.pop_back();
        gen(nums, res, curr, idx + 1);
        return;
    }
};
