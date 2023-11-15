class Solution {
public:
    int nthUglyNumber(int n, int A, int B, int C) {
        long long low = 1, high = 2 * 1e9;
        long long ans = -1;
        long a = long(A);
        long b = long(B);
        long c = long(C);

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            // Finding the position of ugly number:
            // (A U B U C) = A + B + C - (A ∩ B) - (B ∩ C) - (C ∩ A) + (A ∩ B ∩ C)
            count += mid / a;
            count += mid / b;
            count += mid / c;
            count -= mid / lcm(a, b);
            count -= mid / lcm(b, c);
            count -= mid / lcm(c, a);
            count += mid / lcm(a, lcm(b, c));

            if(count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};