class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& ans) {
        ans.push_back(current);  // Include the current subset in the result
        for (int i = index; i < nums.size(); ++i) {
            current.push_back(nums[i]);  // Include nums[i] in the current subset
            solve(nums, i + 1, current, ans);  // Recur with the next index
            current.pop_back();  // Backtrack by removing nums[i] from the current subset
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(nums, 0, current, ans);
        return ans;
    }
};
