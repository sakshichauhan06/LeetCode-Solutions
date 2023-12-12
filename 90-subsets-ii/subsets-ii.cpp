class Solution {
public:
    void findSubsets(vector<int> ip, vector<int> op, set<vector<int>> &ans, int currIdx) {
        if(currIdx >= ip.size()) {
            ans.insert(op);
            return;
        }
        op.push_back(ip[currIdx]);
        findSubsets(ip, op, ans, currIdx + 1);
        op.pop_back();
        findSubsets(ip, op, ans, currIdx + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> op;
        int n = nums.size();

        findSubsets(nums, op, ans, 0);
        vector<vector<int>> res{ans.begin(), ans.end()};

        return res;
    }
};