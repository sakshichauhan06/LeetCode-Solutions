class Solution {
public:
    vector<int> solve(vector<int> prev) {
        vector<int> v;
        v.push_back(1);
        int n = prev.size();
        for(int i = 0; i < n - 1; i++) {
            int sum = prev[i] + prev[i + 1];
            v.push_back(sum);
        }
        v.push_back(1);
        return v;
    }

    vector<vector<int>> generate(int numRows) {
        int k = 1;
        vector<vector<int>> ans;
        ans.push_back({1});

        if(numRows == 1) {
            return ans;
        } else {
            vector<int> prev = {1};
            for(int i = 0; i < numRows - 1; i++) {
                vector<int> new_v = solve(prev);
                ans.push_back(new_v);
                prev = new_v;
            }
        }

        return ans;
    }
};