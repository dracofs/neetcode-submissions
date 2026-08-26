class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        int curr_max = temperatures[0];
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > s.top().first) {
                int idx = s.top().second; s.pop();
                res[idx] = i - idx;
            }
            s.push({temperatures[i], i});
        }
        return res;
    }
};
