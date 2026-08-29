class Solution {
public:
    int findInit(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }

        return l;
    }

    int search(vector<int>& nums, int target) {
        int s = nums.size();

        int index = findInit(nums);
        cout << "Order starts at index: " << index << endl;
        int l, r;
        if (target <= nums[s - 1]) { 
            l = index, r = s - 1;
        } else {
            l = 0, r = index - 1;
        }

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
};
