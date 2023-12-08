class Solution {
public:
    vector<int> xpath = {-2, -2, -1, -1, 1, 1, 2, 2};
    vector<int> ypath = {-1, 1, -2, 2, -2, 2, -1, 1};
    bool isvalid(int x, int y, int n) {
        if(x < 0 or y < 0 or x >= n or y >= n) return false;
        return true;
    }
    bool helper(int x, int y, int curr, vector<vector<int>> &grid) {
        
        int n = grid.size();
        if(!isvalid(x, y, n)) return false;
        if(grid[x][y] == n*n - 1) return true;

        bool res = false;
        for(int i= 0; i < xpath.size(); ++i) {
            int newx = x + xpath[i];
            int newy = y + ypath[i];
            if(isvalid(newx, newy, n) and grid[newx][newy] == curr+1) 
                res = res | helper(newx, newy, curr+1, grid);
        }

        return res;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        return helper(0, 0, 0, grid);
    }
};