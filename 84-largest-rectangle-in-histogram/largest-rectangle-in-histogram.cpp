class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl, nsr;
        stack<int> stk;

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                nsl.push_back(-1);
            } else {
                nsl.push_back(stk.top());
            }
            stk.push(i);
        }

        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) {
                nsr.push_back(n);
            } else {
                nsr.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nsr.begin(), nsr.end());

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int l = heights[i];
            int b = nsr[i] - nsl[i] - 1;
            int area = l * b;
            ans = max(area, ans);
        }

        return ans;
    }
}; 