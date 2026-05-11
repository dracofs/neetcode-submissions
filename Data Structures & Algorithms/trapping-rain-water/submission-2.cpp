class Solution {
public:
    int trap(vector<int>& height) {
        // fix one pointer on curr height, move next to find >= height
        // calculate water in between, add to running val, move prev 
        // pointer to next 

        // int left = 0, right = 1;

        // while (height[left] == 0)
        // { 
        //     left++;
        //     right++;
        // }

        // int debt = 0;
        // int totalWater = 0;
        // while (right < height.size() && left < right) {
        //     if (height[right] < height[left]) {
        //         debt += height[right];
        //         right++;
        //     } else {
        //         int max = (right - left - 1) * height[left];
        //         totalWater += max - debt;
        //         left = right;
        //         right++;
        //         debt = 0;
        //     }
        // }

        // return totalWater;

        vector<int> left(height.size(), 0);
        vector<int> right(height.size(), 0);

        left[0] = 0;
        right[height.size() - 1] = 0;

        int leftMax = height[0];
        int rightMax = height[height.size() - 1];

        for (int i = 1; i < height.size(); ++i) {
            leftMax = max(leftMax, height[i - 1]);
            left[i] = leftMax;
        }

        for (int i = height.size() - 2; i >= 0; --i) {
            rightMax = max(rightMax, height[i + 1]);
            right[i] = rightMax;
        }

        int maxWater = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] < right[i] && height[i] < left[i]) maxWater += min(right[i], left[i]) - height[i];
        }

        return maxWater;
    }
};
