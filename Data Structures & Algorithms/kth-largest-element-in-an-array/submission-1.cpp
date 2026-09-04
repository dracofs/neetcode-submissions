class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // O(nlogn)
        // std::sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n - k];

        std::priority_queue<int, vector<int>, std::greater<int>> pq;
        for (const int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
