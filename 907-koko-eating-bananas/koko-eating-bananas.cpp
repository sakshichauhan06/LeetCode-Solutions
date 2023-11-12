class Solution {
public:
    bool validHrs(vector<int>& piles, int h, int mid) {
        int count = 0;
        int n = piles.size();

        for(int i = 0; i < n; i++) {
            int k = piles[i] / mid;
            count += k;
            if(piles[i] % mid != 0) {
                ++count;
            }
            if(count > h) {
                return false;
            }
        }

        return (count <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int low = 1, high = piles[n - 1];
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(validHrs(piles, h, mid)) {
                ans = mid; 
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};