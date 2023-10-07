class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> lsum, rsum, ans;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            lsum.push_back(sum);
        }

        sum = 0;

        for(int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            rsum.push_back(sum);
        }
        reverse(rsum.begin(), rsum.end());

        for(int i = 0; i < n; i++) {
            int k = abs(lsum[i] - rsum[i]);
            ans.push_back(k);
        }

        return ans;
    }
};