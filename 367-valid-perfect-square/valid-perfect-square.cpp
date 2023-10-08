class Solution {
public:
    bool isPerfectSquare(int num) {
        int k = num/2;
        int low = 1, high = k;

        if(num == 1) {
            return true;
        }

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(mid*mid == num) {
                return true;
            } else if(mid*mid < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }
};