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
        uint32_t x = n + (n >> 1);
        return (x & x + 1) == 0;
    }
};