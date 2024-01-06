class Solution {
public:
    long gcd(long a, long b) {
        if(a % b == 0) {
            return b;
        } else {
            return gcd(b, a % b);
        }
    }

    void binSearch(long l, long h, int d1, int d2, long lcm, long &ans, int n1, int n2) {
        if(l <= h) {
            long m = l + (h - l) / 2;
            long a = m - (m / d1);
            long b = m - (m / d2);
            long c = m - (m / d1) - (m / d2) + (m / lcm);

            if(a >= n1 && b >= n2 && (a + b - c) >= n1 + n2) {
                ans = m;
                binSearch(l, m - 1, d1, d2, lcm, ans, n1, n2);
            } else {
                binSearch(m + 1, h, d1, d2, lcm, ans, n1, n2);
            }
        }
    }

    int minimizeSet(int d1, int d2, int u1, int u2) {
        long l = 1, h = INT_MAX;
        long g = gcd(max(d1, d2), min(d1, d2));
        long lcm = (long(d1) * long(d2)) / g;
        long ans = INT_MAX;

        binSearch(l, h, d1, d2, lcm, ans, u1, u2);

        return int(ans);
    }
};