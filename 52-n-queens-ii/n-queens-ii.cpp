class Solution {
public:
    bool validRow(vector<vector<char>> &grid, int cur_col, int n) {
        for(int i = 0; i < n; i++) {
            if(grid[cur_col][i] == 'Q') {
                return false;
            }
        }
        return true;
    }

    bool validCol(vector<vector<char>> &grid, int cur_row, int n) {
        for(int i = 0; i < n; i++) {
            if(grid[i][cur_row] == 'Q') {
                return false;
            }
        }
        return true;
    }

    bool validDiagonal(vector<vector<char>> &grid, int cur_col, int cur_row, int n) {
        int i = cur_col;
        int j = cur_row;

        // Top left diagonal
        while(i >= 0 && j >= 0) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        // Top right diagonal
        i = cur_col;
        j = cur_row;
        while(i >= 0 && j < n) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        // Bottom left diagonal
        i = cur_col;
        j = cur_row;
        while(i < n && j >= 0) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i++;
            j--;
        }

        // Bottom right diagonal
        i = cur_col;
        j = cur_row;
        while(i < n && j < n) {
            if(grid[i][j] == 'Q') {
                return false;
            }
            i++;
            j++;
        }

        return true;
    }

    bool isValid(vector<vector<char>> &grid, int cur_col, int cur_row, int n) {
        return validRow(grid, cur_col, n) && validCol(grid, cur_row, n) && validDiagonal(grid, cur_col, cur_row, n);
    }

    vector<string> populate(vector<vector<char>> &grid, int n) {
        vector<string> res;
        for(int i = 0; i < n; i++) {
            string temp = "";
            for(int j = 0; j < n; j++) {
                temp += grid[i][j];
            }
            res.push_back(temp);
        }
        return res;
    }

    void solve(vector<vector<char>> &grid, int cur_row, int n, vector<vector<string>> & ans) {
        if(cur_row == n) {
            vector<string> vs = populate(grid, n);
            ans.push_back(vs);
            return;
        }

        for(int cur_col = 0; cur_col < n; cur_col++) {
            if(isValid(grid, cur_col, cur_row, n)) {
                grid[cur_col][cur_row] = 'Q';
                solve(grid, cur_row + 1, n, ans);
                grid[cur_col][cur_row] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        solve(grid, 0, n, ans);

        int k = ans.size();
        return k;
    }
};