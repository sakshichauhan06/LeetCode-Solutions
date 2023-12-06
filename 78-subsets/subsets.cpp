class Solution {
public:
    void genSubsets(vector<int> ip, vector<int> op, vector<vector<int>> &ans) {
        if(ip.size() == 0) {
            ans.push_back(op);
            return;
        }
        int ele = ip[0];
        ip.erase(ip.begin() + 0);
        genSubsets(ip, op, ans);
        op.push_back(ele);
        genSubsets(ip, op, ans);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ip = nums;
        vector<int> op;
        genSubsets(ip, op, ans);

        return ans;
    }
};