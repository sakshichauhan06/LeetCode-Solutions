class Solution {
public:
    int count(int m, int n, int k, int mid) {
        int res = 0;

        for(int i = 1; i <= m; i++) {
            res += min(n, mid / i);
        }

        return res;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 0;
        int high = m * n;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(count(m, n, k, mid) < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};