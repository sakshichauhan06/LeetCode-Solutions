class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int a = 0; a < (n - 3); a++) {
            if(a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            for(int b = a + 1; b < (n - 2); b++) {
                if(b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                long long new_target = (long long)target - (long long)nums[a] - (long long)nums[b];
                int c = b + 1;
                int d = n - 1;
                
                while(c < d) {
                    int new_sum = nums[c] + nums[d];
                    if(new_sum < new_target) {
                        c++;
                    } else if(new_sum > new_target) {
                        d--;
                    } else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        int t_c = nums[c];
                        int t_d = nums[d];
                        while(c < d && t_c == nums[c]) {
                            c++;
                        }
                        while(c < d && t_d == nums[d]) {
                            d--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};