class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> left(n);
        vector<int> right(n);

        stack<pair<int, int>> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] < s.top().first) {
                right[s.top().second] = i - 1;
                s.pop();
            }
            s.push({heights[i], i});
        }

        while (!s.empty()) {
            right[s.top().second] = n - 1;
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[i] < s.top().first) {
                left[s.top().second] = i + 1;
                s.pop();
            }
            s.push({heights[i], i});
        }

        while (!s.empty()) {
            left[s.top().second] = 0;
            s.pop();
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int curr = heights[i] * (right[i] - left[i] + 1);
            res = max(res, curr);
        }
        return res;
    } 
};
