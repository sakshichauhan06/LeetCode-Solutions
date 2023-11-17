class Solution {
public:
    bool existsVector(vector<int>& v, int target) {
        int n = v.size();
        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(v[mid] == target) {
                return true;
            } else if(v[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) {
            return false;
        }

        for(int i = 0; i < n; i++) {
            if(existsVector(matrix[i], target)) {
                return true;
            }
        }

        return false;
    }
};