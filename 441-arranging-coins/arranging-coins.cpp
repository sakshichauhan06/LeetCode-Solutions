class Solution {
public:
    long long solve(long long n) {
        long long k = (n * (n + 1)) / 2;
        return k;
    }
    int arrangeCoins(int n) {
        long long low = 1, high = n;

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long sum = solve(mid);
            if(sum == n) {
                return mid;
            } else if(sum < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;

    }
};