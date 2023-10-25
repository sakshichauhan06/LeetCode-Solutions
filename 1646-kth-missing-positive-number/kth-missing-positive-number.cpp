class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, h = n;

        while(l < h) {
            int mid = l + (h - l) / 2;
            int miss = arr[mid] - 1 - mid;
            if(k <= miss) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }

        return h + k;
    }
};