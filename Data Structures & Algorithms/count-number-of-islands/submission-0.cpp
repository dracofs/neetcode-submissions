class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    search(grid, r, c);
                    count++;
                }
            }
        }
        return count;
    }
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void search(vector<vector<char>>& grid, int r, int c) {
        grid[r][c] = '0';
        
        for (auto& dir : dirs) {
            int rn = r + dir.first;
            int rc = c + dir.second;

            if (rn >= 0 && rn < grid.size() && rc >= 0 && rc < grid[0].size() && grid[rn][rc] == '1') {
                search(grid, rn, rc);
            }
        }

        return;
    }
};
