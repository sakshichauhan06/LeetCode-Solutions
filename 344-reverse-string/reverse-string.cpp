class Solution {
public:
    void revPrint(vector<char>& s, int idx, int n) {
        if((idx - 1) > (n - idx)) {
            return;
        }
        swap(s[idx - 1], s[n - idx]);
        revPrint(s, idx + 1, n);
    }
    
    void reverseString(vector<char>& s) {
        
        int n = s.size();
        revPrint(s, 1, n);
        
        return;
    }
};