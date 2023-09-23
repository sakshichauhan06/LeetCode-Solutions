class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ngr, ans(n);
        stack<int> stk;

        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && heights[stk.top()] <= heights[i]) {
                stk.pop();
                ans[i]++;
            }
            if(stk.empty()) {
                ngr.push_back(-1);
            } else {
                ans[i]++;
                ngr.push_back(stk.top());
            }
            stk.push(i);
        }

        return ans;
    }
};