class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // check rows
        for (int row = 0; row < 9; ++row) {
            vector<bool> seen(9);
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] != '.') {
                    if (seen[board[row][col]]) return false;
                    else seen[board[row][col]] = true;
                } 
            }
        }

        // check cols
        for (int col = 0; col < 9; ++col) {
            vector<bool> seen(9);
            for (int row = 0; row < 9; ++row) {
                if (board[row][col] != '.') {
                    if (seen[board[row][col]]) return false;
                    else seen[board[row][col]] = true;
                }
            }
        }

        // check 3 x 3 squares
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; ++col) {

                vector<bool> seen(9);
                for (int r = row * 3; r < row * 3 + 3; r++) {
                    for (int c = col * 3; c < col * 3 + 3; c++) {
                        if (board[r][c] != '.') {
                            if (seen[board[r][c]]) return false;
                            else seen[board[r][c]] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};
