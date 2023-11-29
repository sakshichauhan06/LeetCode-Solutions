class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        for(auto w : words) {
            int prev = -1;
            for(int i = 0; i < w.size(); i++) {
                int idx = upper_bound(mp[w[i]].begin(), mp[w[i]].end(), prev) - mp[w[i]].begin();
                
                if(idx == mp[w[i]].size()) {
                    break;
                }

                prev = mp[w[i]][idx];
                if(i == w.size() - 1) ans++;
            }
        }

        return ans;
    }
};