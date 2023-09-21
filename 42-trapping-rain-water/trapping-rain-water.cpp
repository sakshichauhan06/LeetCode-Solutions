class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> mgl, mgr;
        stack<int> stk;

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && stk.top() <= height[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                mgl.push_back(-1);
            } else {
                mgl.push_back(stk.top());
            }
            stk.push(stk.empty() ? height[i] : max(stk.top(), height[i]));
        }

        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= height[i]) {
                st.pop();
            }
            if(st.empty()) {
                mgr.push_back(-1);
            } else {
                mgr.push_back(st.top());
            }
            st.push(st.empty() ? height[i] : max(st.top(), height[i]));
        }
        reverse(mgr.begin(), mgr.end());

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(mgl[i] == -1 || mgr[i] == -1) {
                continue;
            } else {
                int mini = min(mgl[i], mgr[i]);
                int k = mini - height[i];
                ans += k;
            }
        }

        return ans;
    }
};