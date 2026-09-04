class Solution {
public:
    std::vector<std::pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int maxarea = 0;
        for (int row = 0; row < r; row++) {
            for (int col = 0; col < c; col++) {
                if (grid[row][col] == 1) {
                    int area = bfs(grid, row, col);
                    maxarea = max(maxarea, area);
                }
            }
        }
        return maxarea;
    }

    int bfs(std::vector<std::vector<int>>& grid, int row, int col) {

        std::queue<std::pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 0;
        int res = 1;
        
        while(!q.empty()) {
            std::pair<int, int> p = q.front();
            q.pop();

            for (const auto& dir : dirs) {
                int r = p.first + dir.first;
                int c = p.second + dir.second;

                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1) {
                    grid[r][c] = 0;
                    q.push({r, c});
                    res++;
                }
            }
        }

        return res;
    }
};
