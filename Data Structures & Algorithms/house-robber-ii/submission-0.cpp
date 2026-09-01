class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return *max_element(nums.begin(), nums.end());

        // 1 => n - 1
        vector<int> dp1(n); dp1[1] = nums[1]; dp1[2] = max(nums[1], nums[2]);

        // 0 => n - 2
        vector<int> dp2(n); dp2[0] = nums[0]; dp2[1] = max(nums[0], nums[1]);

        for (int i = 3; i < n; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
            dp2[i - 1] = max(dp2[i - 2], dp2[i - 3] + nums[i - 1]);
        }
        
        return max(dp1[n - 1], dp2[n - 2]);
    }
};
