class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0;
        long long high = sqrt(c);

        if(c <= 1) return true;

        while(low <= high) {
            long long target = (low * low) + (high * high);
            if(target == c) {
                return true;
            } else if(target < c) {
                low++;
            } else {
                high--;
            }
        }

        return false;
    }
};