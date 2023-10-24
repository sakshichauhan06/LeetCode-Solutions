class Solution {
public: 
    bool binSearch(vector<int>& arr, int target, int i) {
        int n = arr.size();
        int l = 0, h = n - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(arr[mid] == target && mid != i) {
                return true;
            } else if(arr[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        bool ans = false;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; i++) {
            int k = 2 * arr[i];
            ans = binSearch(arr, k, i);
            if(ans == true) break;
        }

        return ans;
    }
};