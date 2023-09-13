class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ngr;
        stack<int> stk;

        for(int i = m - 1; i >= 0; i-- ) {
            while(!stk.empty() && nums2[stk.top()] <= nums2[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                ngr.push_back(-1);
            } else {
                ngr.push_back(stk.top());
            }
            stk.push(i);
        }
        reverse(ngr.begin(), ngr.end());

        unordered_map<int, int> mp;
        for(int i = 0; i < m; i++) {
            mp[nums2[i]] = ngr[i];
        }
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            // cout<<mp[nums1[i]]<<", ";
            if(mp[nums1[i]] == -1) {
                ans.push_back(mp[nums1[i]]);
            } else {
                ans.push_back(nums2[mp[nums1[i]]]);
            }
        }


        return ans;
    }
};