class Solution {
public:
    bool validSubset(vector<int> &nums, int target, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int a = 0, b = k;
        int maxi = sum;

        while(b < n) {
            sum -= nums[a++];
            sum += nums[b++];
            maxi = max(maxi, sum);
        }

        return (maxi >= target);
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(validSubset(nums, target, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};