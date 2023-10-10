class Solution {
public:
    void solve(vector<int> &nums, vector<int> &v, int target, vector<vector<int>> &ans, int i) {
        if(target == 0) {
            ans.push_back(v);
        }
        if(nums.size() == 0) {
            return;
        }

        while(i < nums.size() && target - nums[i] >= 0) {
            v.push_back(nums[i]);
            solve(nums, v, target - nums[i], ans, i);
            i++;
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<int> s(candidates.begin(), candidates.end());
        vector<int> nums;
        nums.assign(s.begin(), s.end());
        vector<vector<int>> ans;
        vector<int> v;
        int i = 0;
        solve(nums, v, target, ans, i);

        return ans;
    }
};