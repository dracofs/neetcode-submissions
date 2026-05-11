class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check each row
        // Check each column
        // Check each 3x3 cell
        
        return (checkRows(board) && checkCols(board) && checkCells(board));
    }

    bool checkRows(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            if (!checkRow(board, i)) return false;
        }
        return true;
    }

    bool checkRow(vector<vector<char>>& board, int i) {
        vector<bool> seen(board.size(), false);
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] == '.') continue;
            if (seen[board[i][j] - '1']) return false;
            seen[board[i][j] - '1'] = true;
        }
        return true;
    }

    bool checkCols(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            if (!checkCol(board, i)) return false;
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, int i) {
        vector<bool> seen(board.size(), false);
        for (int j = 0; j < board.size(); ++j) {
            if (board[j][i] == '.') continue;
            if (seen[board[j][i] - '1']) return false;
            seen[board[j][i] - '1'] = true;
        }
        return true;
    }

    bool checkCells(vector<vector<char>>& board) {
        for (int i = 0; i < board.size() / 3; ++i) {
            for (int j = 0; j < board.size() / 3; ++j) {
                if (!checkCell(board, i , j)) return false;
            }
        }
        return true;
    }

    bool checkCell(vector<vector<char>>& board, int i, int j) {
        vector<bool> seen(board.size(), false);
        for (int k = i * 3; k < 3 * i + 3; ++k) {
            for (int r = j * 3; r < 3 * j + 3; ++r) {
                if (board[k][r] == '.') continue;
                if (seen[board[k][r] - '1']) return false;
                seen[board[k][r] - '1'] = true;
            }
        }
        return true;
    }
};
