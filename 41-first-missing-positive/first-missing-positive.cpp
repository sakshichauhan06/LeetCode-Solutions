class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> vis(n, false);

        while(i < n) {
            if(!vis[i] && nums[i] != i + 1 && nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1] ) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                vis[i] = true;
                i++;
            }
        }

        int ans = n + 1;

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                ans = i + 1;
                break;
            }
        }

        return ans;
    }
};