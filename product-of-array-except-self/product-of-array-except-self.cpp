class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = {};
        int n = nums.size();
        int s = n + 1;
        vector<int> left(s, 1), right(s, 1);

        for(int i = 1; i < s; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }   

        for(int i = s - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i];
        } 

        int i = s - 2, j = s - 1;
        while(i >= 0) {
            int val = left[i] * right[j];
            ans.push_back(val);
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};