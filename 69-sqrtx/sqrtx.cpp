class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }

        int low = 0, high = x;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(mid * mid == x) {
                return mid;
            } else if(mid * mid < x) {
                low = mid + 1;
            } else if(mid * mid > x) {
                high = mid - 1;
            }
        }

        return high;
    }
};