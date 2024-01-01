class Solution {
public:
    void getSubsets(vector<int> ip, vector<int> op, vector<vector<int>> &ans) {
        if(ip.size() == 0) {
            ans.push_back(op);
            return;
        }
        int temp = ip[0];
        ip.erase(ip.begin() + 0);
        getSubsets(ip, op, ans);
        op.push_back(temp);
        getSubsets(ip, op, ans);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ip = nums;
        vector<int> op;
        vector<vector<int>> ans;
        getSubsets(ip, op, ans);

        return ans;
    }
};