class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ngr;
        stack<int> stk;
        int n = temperatures.size();

        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                ngr.push_back(0);
            } else {
                ngr.push_back(stk.top());
            }
            stk.push(i);
        }
        reverse(ngr.begin(), ngr.end());

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(ngr[i] == 0) {
                ans.push_back(0);
            } else {
                int k = abs(ngr[i] - i);
                ans.push_back(k);
            }
        }

        return ans;
    }
};