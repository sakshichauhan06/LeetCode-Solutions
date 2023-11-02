class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> psum;
        int n = nums.size();
        int s = queries.size();
        vector<int> ans(s);
        sort(nums.begin(), nums.end());
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            psum.push_back(sum);
        }

        for(int i = 0; i < s; i++) {
            int idx = upper_bound(psum.begin(), psum.end(), queries[i]) - psum.begin();
            ans[i] = idx;
        }

        return ans;

    }
};