class Solution {
public:
    void solve(vector<int> &nums, vector<int> &op, int i, vector<vector<int>> &ans) {
        if(i == nums.size()) {
            ans.push_back(op);
            return;
        }
        solve(nums, op, i + 1, ans);

        op.push_back(nums[i]);
        solve(nums, op, i + 1, ans);
        op.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(nums, op, 0, ans);

        return ans;
    }
};