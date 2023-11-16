class Solution {
public:
    bool possible(vector<int>& nums, int mid, int t) {
        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            double k = ceil(static_cast<double>(nums[i]) / mid);
            sum += k;
        }

        return (sum <= t);
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(possible(nums, mid, threshold)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};