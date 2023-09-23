class Solution {
public:
    static bool cmp(string &first, string &second) {
        return first.length() < second.length();
    }    

    bool preceds(string &predecessor, string &word) {
        if (predecessor.length() != word.length()-1)
            return false;
        int first = 0, second = 0, misMatches = 0;
        while (first < predecessor.length() && misMatches <= 1) 
            if (predecessor[first] != word[second]) {
                second++;
                misMatches++;
            } else {
                first++;
                second++;
            }
        return misMatches <= 1;
        
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        vector<int> lis(words.size(), 1);
        int ans = 1;
        for (int i = 1; i < words.size(); i++)
            for (int j = 0; j < i; j++) 
                if (preceds(words[j], words[i])) {
                    lis[i] = max(lis[i], lis[j]+1);
                    ans = max(ans,lis[i]);                    
                }
        return ans;
    }
};