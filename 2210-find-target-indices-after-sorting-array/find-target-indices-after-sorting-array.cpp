class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int first = -1;
        int n = nums.size();
        int l = 0, h = n - 1;

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

        while(first != -1 && first < n && nums[first] == target) {
            ans.push_back(first);
            first++;
        }

        return ans;
    }
};