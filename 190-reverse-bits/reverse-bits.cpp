class Solution {
public:
    bool isItSet(int i, uint32_t n) {
        return n & (1 << i);
    }

    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i <= 31; i++) {
            if(isItSet(i, n)) {
                ans = (1 << (31 - i)) | ans;
            }
        }
        return ans;
    }
};