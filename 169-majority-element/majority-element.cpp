class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candi = -1;
        int votes = 0;

        for(int i = 0; i < n; i++) {
            if(votes == 0) {
                candi = nums[i];
                votes++;
            } else if(candi == nums[i]) {
                votes++;
            } else {
                votes--;
            }
        }

        return candi;
    }
};