class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        int i = 0;

        while(i < n) {
            if(!vis[i] && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                vis[i] = 1;
                i++;
            }
        }

        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                ans.push_back(nums[i]);
                ans.push_back(i+1);
                break;
            }
        }

        return ans;
    }
};