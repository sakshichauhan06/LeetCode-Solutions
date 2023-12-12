class Solution {
public:
    void findComb(string op, string digits, map<char, string> &mp, vector<string> &ans, int curIdx) {
        if(op.length() >= digits.length()) {
            ans.push_back(op);
            return;
        }
        char ch = digits[curIdx];
        string s = mp[ch];

        for(int i = 0; i < s.length(); i++) {
            op += s[i];
            findComb(op, digits, mp, ans, curIdx + 1);
            op.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> ans;

        if(digits.length() == 0) {
            return ans;
        }

        findComb("", digits, mp, ans, 0);

        return ans;
    }
};