class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort then fix index then run two sum algo
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            
            while (i > 0 && nums[i] == nums[i - 1]) i++;

            int target = -nums[i];
            solveTwoSum(nums, i + 1, target, result);
            
        }

        return result;
    }

    void solveTwoSum(vector<int>& nums, int index, int target, vector<vector<int>>& result) {
        int left = index;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                result.push_back({nums[index - 1], nums[left], nums[right]});
                left++;
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            } 
            else if (sum < target) left++;
            else right--;
        }
    }
};

    