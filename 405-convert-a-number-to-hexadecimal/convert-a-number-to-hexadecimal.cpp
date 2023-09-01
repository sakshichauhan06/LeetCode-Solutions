class Solution {
public:
    string toHex(int num) {
        string k = "0123456789abcdef";
        unsigned int n = num;
        string ans = "";
        if(n == 0) {
            return "0";
        }
        while(n > 0) {
            int x = n % 16;
            ans += k[x];
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};