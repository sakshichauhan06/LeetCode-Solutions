class Solution {
public:
    int binSearch(vector<int>& arr, int target, int n) {
        int l = 0;
        int h = n - 1;
        int ans = -1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(arr[mid] > arr[mid + 1]) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        int ans = binSearch(arr, maxi, n);

        return ans;
    }
};