class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](pair<int, int> a, pair<int, int> b){
            return b.first * b.first + b.second * b.second > a.first * a.first + a.second * a.second;
        };
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq;

        for (const auto& point : points) {
            pq.push({point[0], point[1]});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {   
            pair<int, int> top = pq.top(); pq.pop();
            res.push_back({top.first, top.second});
        }
        
        return res;
    }
};
