class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // maxp can only increase or stay the same
        int maxp = nums[0], currmax = nums[0], currmin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int t = currmax;
            vector<int> s = {nums[i], t * nums[i], currmin * nums[i]};
            currmax = *max_element(s.begin(), s.end());
            currmin = *min_element(s.begin(), s.end());
            maxp = max(currmax, maxp);
        }

        return maxp;
    }
};
