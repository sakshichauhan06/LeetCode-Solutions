class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int a = 0, b = n - 1, count = 0;
        sort(nums.begin(), nums.end());

        while(a < b) {
            int sum = nums[a] + nums[b];
            if(sum < k) {
                a++;
            } else if(sum > k) {
                b--;
            } else {
                count++;
                a++;
                b--;
            }
        }

        return count;
    }
};