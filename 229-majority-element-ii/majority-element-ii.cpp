class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int freq1 = 0, freq2 = 0;
        int majo1 = INT_MIN, majo2 = INT_MIN;

        for(int i = 0; i < n; i++) {
            if(majo1 == nums[i]) {
                freq1++;
            } else if(majo2 == nums[i]) {
                freq2++;
            } else if(freq1 == 0) {
                majo1 = nums[i];
                freq1 = 1;
            } else if(freq2 == 0) {
                majo2 = nums[i];
                freq2 = 1;
            }else {
                freq1--;
                freq2--;
            }
        }

        vector<int> ans;
        int count1 = 0, count2 = 0;

        for(int i = 0; i < n; i++) {
            if(majo1 == nums[i]) {
                count1++;
            }
            if(majo2 == nums[i]) {
                count2++;
            }
        }

        if(count1 > n/3) {
            ans.push_back(majo1);
        }

        if(count2 > n/3 && majo1 != majo2) {
            ans.push_back(majo2);
        }

        return ans;
    }
};