class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int low = 1, high = n;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long k =(long long) mid * (mid + 1) / 2;
            if(k <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};