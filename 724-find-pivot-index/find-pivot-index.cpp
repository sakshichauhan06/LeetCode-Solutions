class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> lsum, rsum;
        int sum = 0;

        lsum.push_back(0);
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
        rsum.push_back(0);

        for(int i = 0; i < n; i++) {
            if(lsum[i] == rsum[i + 1]) {
                return i;
            }
        }

        return -1;

    }
};