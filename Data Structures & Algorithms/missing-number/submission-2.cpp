class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int l = nums.size();
        int sum = 0;
        for (const int& n : nums) { sum += n; }
        return (l * (l + 1)) / 2 - sum;
    }
};
