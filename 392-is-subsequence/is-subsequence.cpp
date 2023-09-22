class Solution {
public:
    bool isSubsequence(string s, string t) {
        int x=0;
        for(int i=0; i<t.length(); i++){
            if(s[x]==t[i]){
                x++;
            }
            if(x==s.size())
                return true;
        }
        return x==s.size();
    }
};