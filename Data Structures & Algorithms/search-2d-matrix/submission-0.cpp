class Solution {
public:
    pair<int, bool> binsearch(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;

            if (arr[mid] == target) return {0, true};
            else if (arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        if (arr[mid] < target) return {1, false};
        return {-1, false};
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;

        while (low <= high) {
            int mid = low + high;

            pair<int, bool> res = binsearch(matrix[mid], target);
            if (res.second == true) return true;
            else {
                if (res.first == -1) high = mid - 1;
                else low = mid + 1;
            }
        }

        return false;
    }
};
