class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        vector<vector<int>> buckets(size + 1);
        unordered_map<int, int> freqs;

        for (const int& num : nums) {
            freqs[num]++;
        }

        for (auto const& [key, val] : freqs) {
            buckets[val].push_back(key);
        }

        vector<int> res;
        int count = k;
        for (int i = buckets.size() - 1; (i >= 0 && count > 0); i--) {
            if (buckets[i].size() != 0) {
                res.insert(res.begin(), buckets[i].begin(), buckets[i].end());
                count -= buckets[i].size();
            }
        }
        return res;
    }
};