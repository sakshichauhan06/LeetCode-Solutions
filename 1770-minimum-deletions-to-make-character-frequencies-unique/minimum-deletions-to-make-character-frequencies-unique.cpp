class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> count;
        int del = 0;
        unordered_set<int> used_freq;

        for(char c : s) {
            count[c]++;
        }

        for(auto i : count) {
            int freq = i.second;
            while(freq > 0 && used_freq.find(freq) != used_freq.end()) {
                freq--;
                del++;
            }
            used_freq.insert(freq);
        }

        return del;
    }
};