class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[row - 1][col - 1];

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for(int i = 0; i < col; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(count < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
}; 