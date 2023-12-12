class Solution {
public:
    void findSubsets(vector<int> nums, vector<int> op, vector<vector<int>> &ans, int currIdx) {
        ans.push_back(op);
        for(int i = currIdx; i < nums.size(); i++) {
            if(i > currIdx && nums[i] == nums[i - 1]) { // avoiding duplicates
                continue;
            }
            op.push_back(nums[i]);
            findSubsets(nums, op, ans, i + 1);
            op.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> op;
        int n = nums.size();

        findSubsets(nums, op, ans, 0);

        return ans;
    }
};