class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int lo = 0;
        int hi = n - 1;
        int mid;    
        while (lo <= hi) {
            mid = (lo + hi) / 2;
    
            if (nums[mid] < nums[(mid - 1 + n) % n]) return nums[mid];
            else if (nums[hi] < nums[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return nums[mid];
    }
};
