class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, std::less<int>> pq;

        for (const int& stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int next = pq.top(); pq.pop();
            if (first == next) continue;
            pq.push(max(first, next) - min(first, next));
        }

        if (pq.empty()) return 0;
        else return pq.top();
    }
};
