class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int low = 0, high = 1000;
        int n = grades.size();
        sort(grades.begin(), grades.end());

        while(low < high) {
            int mid = (low + high + 1) / 2;
            int k = mid * (mid + 1) / 2;
            if(k > n) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }

        return low;
    }
};