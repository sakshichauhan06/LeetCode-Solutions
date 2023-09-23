class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nsl, nsr, ngl, ngr;
        stack<int> s1, s2, s3, s4;

        for(int i = 0; i < n; i++) {
            while(!s1.empty() && nums[s1.top()] > nums[i]) {
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
            while(!s2.empty() && nums[s2.top()] >= nums[i]) {
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

        for(int i = 0; i < n; i++) {
            while(!s3.empty() && nums[s3.top()] < nums[i]) {
                s3.pop();
            }
            if(s3.empty()) {
                ngl.push_back(-1);
            } else {
                ngl.push_back(s3.top());
            }
            s3.push(i);
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!s4.empty() && nums[s4.top()] <= nums[i]) {
                s4.pop();
            }
            if(s4.empty()) {
                ngr.push_back(n);
            } else {
                ngr.push_back(s4.top());
            }
            s4.push(i);
        }
        reverse(ngr.begin(), ngr.end());

        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            long long smini = i - (nsl[i] + 1) + 1;
            long long smaxi = (nsr[i] - 1) - i + 1;
            long long gmini = i - (ngl[i] + 1) + 1;
            long long gmaxi = (ngr[i] - 1) - i + 1;
            ans += (gmini * gmaxi - smini * smaxi) * nums[i];
        }

        return ans;
    }
};