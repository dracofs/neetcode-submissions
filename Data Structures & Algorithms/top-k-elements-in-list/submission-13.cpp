class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        size_t n = nums.size();
        vector<vector<int>> buckets(n + 1);
        unordered_map<int, int> freq;

        for (const int num : nums) {
            freq[num]++;
        }

        for (const auto& [key, val] : freq) {
            buckets[val].push_back(key);
        }

        vector<int> res;
        for (size_t i{n}; i >= 1; i--) {
            for (int num : buckets[i]) {
                if (res.size() == k) return res;
                res.push_back(num);
            }
        }
        return res;
    }
};
