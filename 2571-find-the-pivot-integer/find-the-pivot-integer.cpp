class Solution {
public:
    int pivotInteger(int n) {
        vector<int> lsum, rsum;
        int sum = 0;

        for(int i = 1; i <= n; i++) {
            sum += i;
            lsum.push_back(sum);
        }
        
        sum = 0;
        for(int i = n; i >= 1; i--) {
            sum += i;
            rsum.push_back(sum);
        }
        reverse(rsum.begin(), rsum.end());

        for(int i = 0; i < n; i++) {
            if(lsum[i] == rsum[i]) {
                return i + 1;
            }
        }

        return -1;
    }
};