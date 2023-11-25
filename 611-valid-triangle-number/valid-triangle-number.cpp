class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int low = j + 1, high = n - 1;
                while(low <= high) {
                    int mid = low + (high - low) / 2;
                    if(nums[i] + nums[j] > nums[mid]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                ans += (high - j);
            }
        }

        return ans;
    }
};