class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }
        string s;
        while(n) {
            if(n % 2 != 0) {
                s.push_back('0');
            } else {
                s.push_back('1');
            }
            n /= 2;
        }
        // reverse(s.begin(), s.end());
        int ans = 0, k = 1;
        for(auto it : s) {
            ans = ans + (it - '0') * k;
            k *= 2;
        }

        return ans;
    }
};