class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i <= n; i++) {
            int k = i;
            int count = 0;
            while(k > 0) {
                if(k%2 != 0) {
                    count++;
                }
                k /= 2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};