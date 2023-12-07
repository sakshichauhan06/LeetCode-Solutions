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

      while(i >= 0 && j >= 0) {
        if(grid[i][j] == 'Q') {
          return false;
        }
        i--;
        j--;
      }

      i = cur_col;
      j = cur_row;
      while(i >= 0 && j < n) {
        if(grid[i][j] == 'Q') {
          return false;
        }
        i--;
        j++;
      }

      i = cur_col;
      j = cur_row;
      while(i < n && j >= 0) {
        if(grid[i][j] == 'Q') {
          return false;
        }
        i++;
        j--;
      }

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

    void solve(vector<vector<char>> &grid, int cur_row, int n, int &ans) {
      if(cur_row == n) {
        ans++;
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
        int ans = 0;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        solve(grid, 0, n, ans);

        return ans;
    }
};