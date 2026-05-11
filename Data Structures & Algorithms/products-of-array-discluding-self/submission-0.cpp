class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size);
        vector<int> suffix(size);

        prefix[0] = 1;
        suffix[size - 1] = 1;
        for (int i = 1; i < size; ++i) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
            suffix[size - i - 1] = suffix[size - i] * nums[size - i]; 
        }

        vector<int> res(size);

        for (int i = 0; i < size; ++i) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
