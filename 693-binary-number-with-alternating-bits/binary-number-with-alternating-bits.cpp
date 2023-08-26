// class Solution {
//  public:
//   bool hasAlternatingBits(uint32_t n) {
//     uint32_t validator = n + (n >> 1);
//     return (validator & validator + 1) == 0;
//   }
// };

class Solution {
public:
    bool hasAlternatingBits(uint32_t n) {
        bool ans = false;
        while(n) {
            int a = n & 1;
            n = n >> 1;
            int b = n & 1;

            if(a == b) {
                return false;
            }
        }
        return true;
    }
};