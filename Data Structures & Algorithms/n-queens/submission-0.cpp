class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        string fill = "";

        for (int i{0}; i < n; i++) {
            fill.push_back('.');
        }

        vector<vector<string>> res;
        vector<string> board(n, fill);


        backtrack(res, board, 0, n);
        return res;
    }

    void backtrack(vector<vector<string>>& res, vector<string> curr, int row, int n) {
        if (row >= n) {
            res.push_back(curr);
            return;
        }

        for (int i{0}; i < n; i++) {
            // try to place queen in diff places
            if (canPlace(curr, row, i)) {
                curr[row][i] = 'Q';
                backtrack(res, curr, row + 1, n);
                // undo
                curr[row][i] = '.';
            } 
        }
        return;
    }

    bool canPlace(vector<string>& board, int row, int col) {

        // check curr row & col
        for (int i{0}; i < board.size(); i++) {
            if (board[row][i] == 'Q') return false;
            if (board[i][col] == 'Q') return false;
        }

        // expand from curr coor
        int x = col, y = row;

        // expand to the top left
        while (x >= 0 && y >= 0) {
            if (board[y][x] == 'Q') return false;
            x--;
            y--;
            
        }

        x = col, y = row;
        // expand to bottom left
        while (x >= 0 && y < board.size()) {
            if (board[y][x] == 'Q') return false;
            x--;
            y++;
        }

        x = col, y = row;
        // expand to top right
        while (x < board[0].size() && y >= 0) {
            if (board[y][x] == 'Q') return false;
            x++;
            y--;
        }

        x = col, y = row;
        // expand to bottom right
        while (x < board[0].size() && y < board.size()) {
            if (board[y][x] == 'Q') return false;
            x++;
            y++;
        }

        return true;
    }
};
