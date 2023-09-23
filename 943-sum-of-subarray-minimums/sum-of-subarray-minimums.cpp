class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl, nsr;
        stack<int> s1, s2;

        for(int i = 0; i < n; i++) {
            while(!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            if(s1.empty()) {
                nsl.push_back(-1);
            } else {
                nsl.push_back(s1.top());
            }
            s1.push(i);
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            } 
            if(s2.empty()) {
                nsr.push_back(n);
            } else {
                nsr.push_back(s2.top());
            }
            s2.push(i);
        }
        reverse(nsr.begin(), nsr.end());

        int ans = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            long long count = 0;
            long long left = nsl[i] + 1;
            long long right = nsr[i] - 1;
            count = ((i - left + 1) * (right - i + 1) * arr[i]) % mod;
            ans = (ans + count) % mod;
        }
        return ans;
    }
};