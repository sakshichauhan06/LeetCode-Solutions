class Solution {
public:
    bool validRow(vector<vector<char>> &board, int cur_row, int cur_val) {
        for(int i = 0; i < 9; i++) {
            if(board[cur_row][i] == (cur_val + '0')) {
                return false;
            }
        }
        return true;
    }

    bool validCol(vector<vector<char>> &board, int cur_col, int cur_val) {
        for(int i = 0; i < 9; i++) {
            if(board[i][cur_col] == (cur_val + '0')) {
                return false;
            }
        }
        return true;
    }

    bool validBox(vector<vector<char>> &board, int cur_row, int cur_col, int cur_val) {
        int x = 3*(cur_row/3);
        int y = 3*(cur_col/3);

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[x + i][y + j] == (cur_val + '0')) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValid(vector<vector<char>> &board, int cur_row, int cur_col, int cur_val) {
        return validRow(board, cur_row, cur_val) && validCol(board, cur_col, cur_val) && validBox(board, cur_row, cur_col, cur_val);
    }

    bool solve(vector<vector<char>> &board, int cur_row, int cur_col) {
        if(cur_row == 9) {
            return true;
        }
        int next_col = 0;
        int next_row = 0;

        if(cur_col == 8) {
            next_row = cur_row + 1;
            next_col = 0;
        } else {
            next_row = cur_row;
            next_col = cur_col + 1;
        }

        if(board[cur_row][cur_col] != '.') {
            return solve(board, next_row, next_col);
        }

        for(int cur_val = 1; cur_val <= 9; cur_val++) {
            if(isValid(board, cur_row, cur_col, cur_val)) {
                board[cur_row][cur_col] = cur_val + '0';
                if(solve(board, next_row, next_col) == true) {
                  return true;
              }
              board[cur_row][cur_col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};