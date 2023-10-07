class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        vector<int> pow;
        map<int, int> mp;
        long long ans = 0;
        int modu = 1e9+7;
        pow.push_back(1);

        for(int i = 1; i <= 21; i++) {
            pow.push_back(pow.back() * 2);
        }

        for(int i = 0; i < n; i++) {
            for(auto it : pow) {
                // if(mp[it - deliciousness[i]] != mp.end()) {
                if(mp.count(it - deliciousness[i])) {
                    ans += mp[it - deliciousness[i]];
                }
            }
            mp[deliciousness[i]]++;
        }

        return ans % modu;
    }
};