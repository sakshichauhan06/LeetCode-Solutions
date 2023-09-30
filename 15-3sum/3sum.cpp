class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int a, b, c;
        sort(nums.begin(), nums.end());

        for(a = 0; a < n - 2; a++) {
            if(a > 0 && nums[a] == nums[a -1]) {
                continue;
            }
            int new_target = 0 - nums[a];
            b = a + 1;
            c = n - 1;
            while(b < c) {
                int k = nums[b] + nums[c];
                if(k < new_target) {
                    b++;
                } else if(k > new_target) {
                    c--;
                } else {
                    ans.push_back({nums[a], nums[b], nums[c]});
                    int t_b = nums[b];
                    int t_c = nums[c];
                    while(nums[b] == t_b && b < n && b < c) {
                        b++;
                    }
                    while(nums[c] == t_c && c >= 0 && b < c) {
                        c--;
                    }
                }
            } 
        }

        return ans;
    }
};