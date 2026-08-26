class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int max_area = 0;
        while (l < r) {
            int min_height = min(heights[l], heights[r]);
            max_area = max(max_area, min_height * (r - l));

            if (min_height == heights[l]) l++;
            else r--;
        }
        return max_area;
    }
};
