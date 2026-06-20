class Solution {
public:
    int binsearch(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;

            if (arr[mid] == target) return target;
            else if (arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }

        return arr[mid];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() - 1;

        while (low <= high) {
            int mid = low + high;

            int res = binsearch(matrix[mid], target);
            if (res == target) return true;
            else if (res < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};
