class Solution {
public:
    void getCombSum(vector<int> &candidates, vector<int> v, int target, vector<vector<int>> &ans, int idx) {
        if(target == 0) {
            ans.push_back(v);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if(candidates[idx] <= target) {
                v.push_back(candidates[i]);
                getCombSum(candidates, v, target - candidates[i], ans, i + 1);
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;

        getCombSum(candidates, v, target, ans, 0);

        return ans;
    }
};