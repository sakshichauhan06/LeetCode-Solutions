class Solution {
public:
    int countBits(int n) {
        int res = 0;
        while(n > 0) {
            res += n % 2;
            n /= 2;
        }
        return res;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int h = 0; h < 12; h++) {
            for(int m = 0; m < 60; m++) {
                if(countBits(h) + countBits(m) == turnedOn) {
                    string s = "";
                    s += to_string(h);
                    s.push_back(':');
                    if(m < 10) {
                        s.push_back('0');
                    }
                    s += to_string(m);
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};