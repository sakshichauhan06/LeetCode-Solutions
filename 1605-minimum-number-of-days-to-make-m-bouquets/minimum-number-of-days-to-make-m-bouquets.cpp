class Solution {
public:
    bool validSeq(vector<int>& bloomDay, int target, int m, int k) {
        int n = bloomDay.size();
        vector<bool> v(n, false);

        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= target) {
                v[i] = true;
            }
        }

        int count = 1, seq = 0;
        for(int i = 1; i < n; i++) {
            if(v[i] == true && v[i] == v[i - 1]) {
                count++;
            } else if(v[i] != v[i - 1]) {
                count = 1;
            }
            if(count == k) {
                seq++;
                count = 0;
            }
        }

        return (seq >= m);

    }

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
        // int low = *min_element(bloomDay.begin(), bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        long long val = m * 1ll * k * 1ll;
        if(val>n) return -1;

        int low = INT_MAX, high = INT_MIN;
        for(int i = 0; i< n; i++) {
            low = min(bloomDay[i], low);
            high = max(bloomDay[i], high);
        }

        // if(m == 1 && k == 1) {
        //     return bloomDay[0];
        // }

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)) {
                // ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};