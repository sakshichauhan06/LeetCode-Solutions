class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        int a, b, c, d;
        sort(nums.begin(), nums.end());

        for(a = 0; a < n - 3; a++) {
            for(b = a + 1; b < n - 2; b++) {
                long long new_target = (long long)target - (long long)nums[a] - (long long)nums[b];
                c = b + 1;
                d = n - 1;
                while(c < d) {
                    int k = nums[c] + nums[d];
                    if(k < new_target) {
                        c++;
                    } else if(k > new_target) {
                        d--;
                    } else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        int t_c = nums[c];
                        int t_d = nums[d];
                        while(t_c == nums[c] && c < n && c < d) {
                            c++;
                        }
                        while(t_d == nums[d] && d >= 0 && c < d) {
                            d--;
                        }
                    }
                }
                while(b + 1 < n && nums[b] == nums[b + 1]) {
                    b++;
                }
            }
            while(a + 1 < n && nums[a] == nums[a + 1]) {
                a++;
            }
        }

        return ans;
    }
};