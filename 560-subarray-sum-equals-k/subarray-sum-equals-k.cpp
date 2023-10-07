class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int ans = 0, sum = 0;
        mp[sum]++;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int new_k = sum - k;
            if(mp.find(new_k) != mp.end()) {
                ans += mp[new_k];
            }
            mp[sum]++;
        }

        return ans;
    }
};