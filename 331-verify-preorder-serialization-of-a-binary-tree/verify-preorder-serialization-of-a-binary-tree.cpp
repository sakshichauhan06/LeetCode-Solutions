class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int slot = 0;
        int i = 0;

        for(int i = 0; i < n; i++) {
            if(preorder[i] == ',') {
                continue;
            }
            if(slot < 0) {
                return false;
            }
            if(preorder[i] == '#') {
                slot--;
            } else {
                while(i < n && preorder[i] != ',') {
                    i++;
                }
                slot++;
            }
        }

        if(slot == -1) {
            return true;
        }
        return false;
    }
};