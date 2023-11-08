class Solution {
public:
    int binSearch(vector<int>& arr, int target, int n) {
        int l = 0;
        int h = n - 1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(arr[mid] == target) {
                return mid;
            } else if(arr[mid] > arr[h]) {
                h--;
            } else if(arr[mid] < target) {
                l++;
            }
        }

        return 0;
    }

    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int maxi = *max_element(arr.begin(), arr.end());
        int ans = binSearch(arr, maxi, n);

        return ans;
    }
};