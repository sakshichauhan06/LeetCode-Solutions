class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        char ans;
        for(int i = 0; i < n; i++) {
            ans = ans ^ s[i] ^ t[i];
        }
        ans = ans ^ t[n];
        return ans;
    }
};