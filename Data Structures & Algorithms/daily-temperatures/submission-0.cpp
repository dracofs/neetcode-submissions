class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        int n = temperatures.size();
        vector<int> res(n, 0);
 
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                s.push({temperatures[i], i});
                continue;
            }

            while (!s.empty() && temperatures[i] > s.top().first) {
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }

        return res;
    }
};
