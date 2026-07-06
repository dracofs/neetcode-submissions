class Solution {
public:
    // finds the starting index of the rotated sorted array
    int find_start(const vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int mid;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (nums[mid] < nums[(mid - 1 + n) % n]) return mid;
            else if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
        return mid;
    }

    int binsearch(vector<int>& nums, int start, int end, int target) {
        int lo = start;
        int hi = end;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) return mid;
            else if (target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int start_idx = find_start(nums);
        int n = nums.size();
        if (nums[start_idx] <= target && target<= nums[n-1]) return binsearch(nums, start_idx, n - 1, target);
        else return binsearch(nums, 0, start_idx, target);
    }
};
