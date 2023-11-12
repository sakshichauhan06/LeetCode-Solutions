class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> space;

        for(int i = 0; i < n; i++) {
            int k = capacity[i] - rocks[i];
            space.push_back(k);
        }

        int ans = 0, i = 0;
        sort(space.begin(), space.end());

        while(additionalRocks >= 0 && i < n) {
            additionalRocks -= space[i];
            i++;
            if(additionalRocks >= 0) {
                ans++;
            }
        }

        return ans;

    }
};