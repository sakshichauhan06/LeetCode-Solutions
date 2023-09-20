class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        int target = sum - x;
        int curr_sum = 0;
        int maxi = 0;
        int i=0, j=0;
        bool found = false;
        
        for(i=0; i<n; i++) {
            curr_sum += nums[i];
            while(j <= i && curr_sum > target) {
                curr_sum -= nums[j];
                j += 1;
            } 
            if(curr_sum == target) {
                found = true;
                maxi = max(maxi, i-j+1);
            }
        }
        
        if(!found) {
            return -1;
        }
        return (n - maxi);
    }
};