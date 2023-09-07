class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while(n) {
            count += (n%2);
            n /= 2;
        }
        return count;
    }

    bool isPrime(int n) {
        if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19) {
            return true;
        }
        return false;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) {
            int k = countSetBits(i);
            if(isPrime(k)) {
                ans++;
            }
        }
        return ans;
    }
};