class Solution {
public:
    int firstidx(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int first = -1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] <= 0) {
                l = mid + 1;
            } else if(nums[mid] > 0) {
                first = mid;
                h = mid - 1;
            }
        }

        return first;
    }

    int lastidx(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int last = -1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] >= 0) {
                h = mid - 1;
            } else {
                last = mid;
                l = mid + 1;
            }
        }

        return last;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int first_pos = firstidx(nums);
        int last_neg = lastidx(nums);

        cout<<first_pos<<" "<<last_neg;

        int count_neg = 0, count_pos = 0;

        if(last_neg == -1 && first_pos == -1 && nums[0] != 0) {
            return n;
        }

        if(last_neg == -1 && first_pos == -1 && nums[0] == 0) {
            return 0;
        }

        if(last_neg != -1) {
            count_neg = last_neg + 1;
        }

        if(first_pos != -1) {
            count_pos = n - first_pos;
        }

        int ans = max(count_neg, count_pos);

        return ans;
    }
};