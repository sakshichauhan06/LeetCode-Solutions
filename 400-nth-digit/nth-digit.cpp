class Solution {
public:
    int ans;

    long long check(int n, int mid) {
        string s = to_string(mid);
        long long len = s.size();
        long long count = 0;

        for(int i = len - 1; i >= 0; i--) {
            int pos = len - i;
            if(i != 0) {
                count += 9 * (pow(10, pos - 1)) * pos;
            } else {
                count += (mid - pow(10, pos - 1)) * pos;
            }
        }

        for(int i = 0; i < len; i++) {
            count++;
            if(count == n) {
                ans = s[i] - '0';
                break;
            }
        }

        return count;
    }

    int findNthDigit(int n) {
        if(n < 10) {
            return n;
        }

        long long low = 1;
        long long high = n;

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = check(n, mid);

            if(count == n) {
                return ans;
            } else if(count < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
         
    }
};