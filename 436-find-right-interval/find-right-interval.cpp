class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair <int, int>> s;
        vector<int> e;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            s.push_back({intervals[i][0], i});
            e.push_back(intervals[i][1]);
        }

        sort(s.begin(), s.end());

        for(int i = 0; i < n; i++) {
            auto k = lower_bound(s.begin(), s.end(), make_pair(e[i], 0)) - s.begin();
            if(k != n) {
                ans.push_back(s[k].second);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};