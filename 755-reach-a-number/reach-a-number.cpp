class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);

        int sum = 0, count = 0;

        while (sum < target || (sum - target) % 2 != 0) {
            count++;
            sum += count;
        }

        return count;
    }
};
