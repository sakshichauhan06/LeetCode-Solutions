class Solution {
public:
    int binSearch(int target, vector<int>& nums2) {
        int n = nums2.size();
        int l = 0, h = n - 1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums2[mid] == target) {
                return target;
            } else if(nums2[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return -1;
    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans = -1;
        for(int i = 0; i < nums1.size(); i++) {
            ans = binSearch(nums1[i], nums2); 
            if(ans != -1) break;
        }

        return ans;
    }
};