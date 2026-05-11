class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket sort

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        unordered_map<int, int> freqs;

        for (int num : nums) {
            freqs[num]++;
        }

        for (const pair<int, int> freq : freqs) {
            buckets[freq.second].push_back(freq.first);
        }
        
        vector<int> ans;

        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size() && k > 0; ++j) {
                ans.push_back(buckets[i][j]);
                k--;
            }            
        }

        return ans;
    }
};
