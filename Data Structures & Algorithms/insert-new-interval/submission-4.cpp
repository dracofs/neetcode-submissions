class Solution {
public:
    bool overlap(auto& a, auto& b) {
        return !(a[1] < b[0] || a[0] > b[1]);
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return { newInterval };
        vector<vector<int>> res;
        bool merged = false;
        for (int i = 0; i < intervals.size(); i++) {
            
            if (!merged && i == 0 && newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                merged = true;
            }

            if (!merged && i == intervals.size() - 1 && newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
                res.push_back(newInterval);
                merged = true;
                break;
            }

            if (!merged && i > 0 && newInterval[0] > intervals[i - 1][1] && newInterval[1] < intervals[i][0]) {
                res.push_back(newInterval);
                merged = true;
            }

            if (!merged && overlap(intervals[i], newInterval)) {
                while (i < intervals.size() && overlap(intervals[i], newInterval)) {
                    // do merging
                    newInterval = { min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
                    i++;
                }
                res.push_back(newInterval);
                if (i < intervals.size()) res.push_back(intervals[i]);
                merged = true;
                continue;
            }

            res.push_back(intervals[i]);
        }

        return res;
    }
};
