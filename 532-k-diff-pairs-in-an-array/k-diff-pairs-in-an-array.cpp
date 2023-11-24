class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int target = k + nums[i];

            auto idx = lower_bound(nums.begin() + (i + 1), nums.end(), target);

            if (idx != nums.end() && *idx == target) {
                count++;
            }
        }

        return count;
    }
};
