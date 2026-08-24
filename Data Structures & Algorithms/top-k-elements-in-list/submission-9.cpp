class Solution {
public:

    struct cmp {
        bool operator()(const auto& a, const auto& b) {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        std::unordered_map<int, int> freq;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> pq;

        // O(n)
        for (const int num : nums) {
            freq[num]++;
        }

        // O(n)
        for (const auto& [val, f] : freq) {
            pq.push({val, f});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        std::vector<int> res;
        res.reserve(k);

        // O(k) * O(log(k))
        while (!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
