class Compare
{
public:
    bool operator() (std::pair<int, int> p1, std::pair<int, int> p2)
    {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> val_freq;
        for (int num : nums) {
            auto find = val_freq.find(num);
            if (find == val_freq.end()) val_freq.insert({num, 1});
            else find->second++;
        }
        std::priority_queue<std::pair<int, int>, std::vector<pair<int, int>>, Compare> heap;
        for (pair<int, int> val_pair : val_freq) {
            heap.push(val_pair);
        }
        vector<int> res;
        while(k--) {
            pair<int, int> top = heap.top();
            res.push_back(top.first);
            heap.pop();
        }
        return res;
    }
};