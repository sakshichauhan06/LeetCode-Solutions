class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            if(nums2.empty()) {
                break;
            }
            int l = 0, h = nums2.size() - 1;
            while(l <= h) {
                int mid = l + (h - l) / 2;
                if(nums2[mid] == nums1[i]) {
                    ans.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + mid);
                    break;
                } else if(nums2[mid] < nums1[i]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
        }

        return ans;
    }
};