class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++) {
            v.push_back({trips[i][1], trips[i][0]});
            v.push_back({trips[i][2], -trips[i][0]});
        }

        sort(v.begin(), v.end());
        int cur_cap = 0;

        for(int i = 0; i < v.size(); i++) {
            cur_cap += v[i].second;
            if(cur_cap > capacity) {
                return false;
            }
        }

        return true;

    }
};