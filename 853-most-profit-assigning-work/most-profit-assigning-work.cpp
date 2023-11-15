class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<pair <int, int>> vp;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            vp.push_back({difficulty[i], profit[i]});
        }

        sort(vp.begin(), vp.end());

        for(int i = 1; i < n; i++) {
            vp[i].second = max(vp[i - 1].second, vp[i].second);
        }

        // for(auto it : vp) {
        //     cout<<it.first<<"-"<<it.second<<", ";
        // }
        long long max_profit = 0;

        for (int i = 0; i < m; i++) {
            int low = 0;
            int high = n - 1;
            int temp_profit = 0;

            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(vp[mid].first <= worker[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if(high >= 0) {
                max_profit = (long long)max_profit + vp[high].second;
            }
        }

        return max_profit;
    }
};