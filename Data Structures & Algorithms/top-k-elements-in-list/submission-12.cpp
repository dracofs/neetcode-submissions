class Solution {
public:

    // struct cmp {
    //     bool operator()(const auto& a, const auto& b) {
    //         return a.second > b.second;
    //     }
    // };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        size_t n = nums.size();
        std::unordered_map<int, int> freq;
        std::vector<std::vector<int>> buckets(n + 1);

        // O(n)
        for (const int num : nums) {
            freq[num]++;
        }

        // O(n)
        for (const auto& [num, f] : freq) {
            buckets[f].push_back(num);
        }

        std::vector<int> res;
        res.reserve(k);

        // O(n)
        for (size_t i{n}; i >= 1; i--) {
            for (const int val : buckets[i]) {
                if (res.size() == k) return res;
                res.push_back(val);
            }
        }

        return res;
    }
};
