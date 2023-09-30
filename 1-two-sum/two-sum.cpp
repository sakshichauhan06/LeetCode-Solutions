class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        vector<pair <int, int>> vp;
        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});  
        }

        sort(vp.begin(), vp.end());
        int a = 0;
        int b = n - 1;

        while(a < b) {
            int k = vp[a].first + vp[b].first;
            if(k < target) {
                a++;
            } else if(k > target) {
                b--;
            } else {
                ans.push_back(vp[a].second);
                ans.push_back(vp[b].second);
                int t_a = vp[a].first;
                int t_b = vp[b].first;
                while(vp[a].first == t_a && a < n && a < b) {
                    a++;
                }
                while(vp[b].first == t_b && b >= 0 && a < b) {
                    b--;
                }
            }
        }

        return ans;
    }
};