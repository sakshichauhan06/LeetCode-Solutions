class Solution {
public:
    bool possible(vector<int>& nums, int day, int m, int k) {
        int cnt = 0, num = 0;
        for(int i = 0; i< nums.size(); i++) {
            if(nums[i] <= day) cnt++;
            else {
                num += cnt/k;
                cnt = 0;
            }
        }
        num += cnt/k;
        return num>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};