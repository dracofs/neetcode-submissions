class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        
        for (const int val : nums) {
            cout << val << ", ";
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int find = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < nums.size() && right >= 0 && left < right) {
                int sum = nums[left] + nums[right];
                if (sum == find) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                }
                else if (sum < find) left++;
                else right--;
            }
        }
        return res;
    }
};
