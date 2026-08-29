class Solution {
public:
    bool is_in(int target, const vector<int>& arr) {
        int l = 0, r = arr.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (target == arr[mid]) return true;
            if (target < arr[mid]) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int len = matrix[0].size();
        while (l <= r) {
            int mid = (l + r) / 2;

            if (is_in(target, matrix[mid])) return true;
            if (target < matrix[mid][len - 1]) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
