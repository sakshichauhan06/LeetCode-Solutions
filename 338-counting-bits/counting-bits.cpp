class Solution {
public:
    int count(int n) {
        int ans = 0;
        while(n > 0) {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> v;
        for(int i = 0; i <= n; i++) {
            int k = count(i);
            v.push_back(k);
        }
        return v;
    }
};