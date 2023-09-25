class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        int votes = INT_MIN;
        int candi = -1;
        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                mp[nums[i]]++;
            }
        }

        for(auto it : mp) {
            if(it.second > votes) {
                candi = it.first;
                votes = it.second;
            }
        }

        return candi;
    }
};