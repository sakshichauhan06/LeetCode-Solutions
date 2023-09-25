class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        int votes = 0;
        int candi = -1;
        map<int, int> mp;
        multimap<int, int, greater<int>> aise;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                mp[nums[i]]++;
            }
        }

        int maxi = -1;

        for(auto it : mp) {
            maxi = max(it.second, maxi);
            aise.insert({it.second, it.first});
        }

        // for(auto it : aise) {
        //     cout<<it.first<<"->"<<it.second<<", ";
        // }

        for(auto it : aise) {
            candi = it.second;
            break;
        }

        for(auto it : aise) {
            if(it.first == maxi) {
                candi = min(candi, it.second);
            }
        }

        return candi;
    }
};