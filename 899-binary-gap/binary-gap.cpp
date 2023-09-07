class Solution {
public:
    int binaryGap(int n) {
        string s;
        while(n != 0) {
            if(n % 2 != 0) {
                s.push_back('1');
            } else {
                s.push_back('0');
            }
            n /= 2;
        }
        reverse(s.begin(), s.end());
        int count = 0, maxi = 0;
        bool flag = false;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                if(flag) {
                    maxi = max(maxi, count);
                }
                count = 1;
                flag = true;
            } else if(s[i] == '0' && flag) {
                count++;
            }
        }

        return maxi;
    }
};