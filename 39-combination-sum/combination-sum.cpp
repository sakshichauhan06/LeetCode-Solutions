class Solution {
public:
    void solve(vector<int> &nums, vector<int> &v, int target, vector<vector<int>> &ans, int idx) {
        if(target == 0) {
            ans.push_back(v);
        }
        if(idx == nums.size()) {
            return;
        }
        while(idx < nums.size() && target - nums[idx] >= 0) {
            v.push_back(nums[idx]);
            solve(nums, v, target - nums[idx], ans, idx);
            idx++;
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

        solve(nums, v, target, ans, 0);

        return ans;
    }
};