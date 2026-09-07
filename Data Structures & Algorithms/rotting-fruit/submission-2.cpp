class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push( {i, j} );
            }
        }

        // bfs on q
        int time = 0;
        while (!q.empty()) {
            int len = q.size();

            while (len > 0) {
                pair<int, int> curr = q.front(); q.pop();

                for (auto& dir : dirs) {
                    int r = curr.first + dir.first;
                    int c = curr.second + dir.second;
                    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push( {r, c} );
                    }
                }
                len--;
            }
            if (q.empty()) break;
            time++;
        }

        // scan one last time for any remaining fresh fruit
        for (vector<int>& row : grid) {
            for (int& num : row) {
                if (num == 1) return -1;
            }
        }

        return time;
    }
};
