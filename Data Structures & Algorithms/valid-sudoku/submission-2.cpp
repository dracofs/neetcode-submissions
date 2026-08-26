class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {

        for (int r = 0; r < 9; r++) {
            if (!check_row(r, b) || !check_col(r, b) || !check_sqr(r / 3, r % 3, b)) return false;
        }

        return true;
    }

    bool check_row(int r, auto& b) {
        vector<bool> check(10, false);
        for (int i = 0; i < 9; i++) {
            if (b[r][i] == '.') continue;
            if (check[b[r][i] - '0']) return false;
            check[b[r][i] - '0'] = true;
        }
        return true;
    }

    bool check_col(int c, auto& b) {
        vector<bool> check(10, false);
        for (int i = 0; i < 9; i++) {
            if (b[i][c] == '.') continue;
            if (check[b[i][c] - '0']) return false;
            check[b[i][c] - '0'] = true;
        }
        return true;
    }

    bool check_sqr(int r, int c, auto& b) {
        vector<bool> check(10, false);
        for (int i = 3*r; i < 3*r + 3; i++) {
            for (int j = 3*c; j < 3*c + 3; j++) {
                if (b[i][j] == '.') continue;
                if (check[b[i][j] - '0']) return false;
                check[b[i][j] - '0'] = true;
            }
        }
        return true;
    }
};
