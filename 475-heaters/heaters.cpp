class Solution {
public: 
    bool coversAll(vector<int>& houses, vector<int>& heaters, int mid) {
        int n = houses.size();
        int m = heaters.size();
        int i = 0, j = 0;

        while(i < n && j < m) {
            int k = abs(houses[i] - heaters[j]);
            if(k > mid) {
                j++;
            } else {
                i++;
            }
        }

        return i == n;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int low = 0;
        int high = max(*max_element(houses.begin(), houses.end()), *max_element(heaters.begin(), heaters.end()));
        int ans;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(coversAll(houses, heaters, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};