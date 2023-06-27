class Solution {
public:
    int countPairs(vector<int>& d) {
        int n = d.size();
        int count = 0;
        unordered_map<int, int> mp;
        int mod = 1e9+7;

        for(int i = 0; i < n; i++) {
            for(int p = 0; p <= 21; p++) {
                int power = 1<<p;
                if(mp.find(power - d[i]) != mp.end()) {
                    count += mp[power - d[i]];
                }
                count %= mod;
            }
            mp[d[i]]++;
        }

        return count;
    }
};