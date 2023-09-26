class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = -1;
        vector<int> vis(n, false);

        while(i < n) {
            if(!vis[i] && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                vis[i] = true;
                i++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                ans = nums[i];
                break;
            }
        }

        return ans;

    }
};