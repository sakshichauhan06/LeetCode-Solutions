class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int low = 0, high = n - 1, mid = 0;
        vector<int> ans;

        while(low <= high) {
            mid = low + (high - low) / 2;
            if(arr[mid] == x) {
                break;
            } else if(arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }   

        int idx = mid;
        
        if(mid - 1 >= 0 && abs(arr[mid - 1] - x) <= abs(arr[idx] - x)) {
            idx = mid - 1;
        }

        if(mid + 1 < n && abs(arr[mid + 1] - x) < abs(arr[idx] - x)) {
            idx = mid + 1;
        }

        int i = idx - 1;
        int j = idx + 1;
        ans.push_back(arr[idx]);
        k--;

        while(k > 0 && i >= 0 && j < n) {
            if(abs(arr[i] - x) <= abs(arr[j] - x)) {
                ans.push_back(arr[i]);
                k--;
                i--;
            } else {
                ans.push_back(arr[j]);
                k--;
                j++;
            }
        }

        while(i >= 0 && k > 0) {
            ans.push_back(arr[i]);
            k--;
            i--;
        }

        while(j < n && k > 0) {
            ans.push_back(arr[j]);
            k--;
            j++;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};