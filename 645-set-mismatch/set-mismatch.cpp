class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> vis(n, false);
        vector<int> ans;

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
                ans.push_back(nums[i]);
                ans.push_back(i + 1);
                break;
            }
        }

        return ans;
    }
};