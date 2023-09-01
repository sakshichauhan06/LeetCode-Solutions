class Solution {
public:
    string toBin(int n) {
        string s = "";
        while(n > 0) {
            if(n%2 != 0) {
                s.push_back('1');
            } else {
                s.push_back('0');
            }
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int findComplement(int num) {
        string k = toBin(num);
        string x;
        for(auto it : k) {
            if(it == '1') {
                x.push_back('0');
            } else {
                x.push_back('1');
            }
        }
        long long int ans = 0;
        long long int pow = 1;
        for(int i = x.length() - 1; i >= 0; i--) {
            ans += ((x[i] - '0') * pow);
            pow *= 2;
        }
        return ans;
    }
};