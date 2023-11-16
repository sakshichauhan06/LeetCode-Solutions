class Solution {
public:
    bool valid(vector<int>& price, int k, int mid) {
        int n = price.size();
        int lastPrice = price[0];
        int count = 1;

        for(int i = 1; i < n; i++) {
            if(price[i] - lastPrice >= mid) {
                count++;
                lastPrice = price[i];
            }
        }

        return (count >= k);
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int low = 1;
        int high = price[n - 1];
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(valid(price, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};