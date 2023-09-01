class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> a(x), b(y);
        string as = a.to_string();
        string bs = b.to_string();
        int count = 0;
        
        for(int i = 32; i >= 0; i--) {
            if(as[i] != bs[i]) {
                count++;
            } 
        }
        
        return count;
    }
};