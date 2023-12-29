class Solution {
public:
    int getNum(int n, vector<int> &m) {
        if(n <= 1) {
            return 1;
        }
        if(not m[n]) {
            for(int i = 1; i <= n; i++) {
                m[n] += getNum(i - 1, m) * getNum(n - i, m);
            }
        }
        return m[n];
    }

    int numTrees(int n) {
        vector<int> m(20);
        return getNum(n, m);
    }
};