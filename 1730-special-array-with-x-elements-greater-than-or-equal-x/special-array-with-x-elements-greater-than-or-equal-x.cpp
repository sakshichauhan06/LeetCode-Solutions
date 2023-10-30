class Solution {
public:
    int binSearch(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int first = -1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] == target) {
                first = mid;
                h = mid - 1;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        if(first == -1) {
            first = l;
        }

        return first;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = 0;
        int ans = -1;

        while(k <= n) {
            int j = binSearch(nums, k);
            int count = n - j;
            if(count == k) {
                ans = k;
                break;
            }
            k += 1;
        }

        return ans;
    }
};