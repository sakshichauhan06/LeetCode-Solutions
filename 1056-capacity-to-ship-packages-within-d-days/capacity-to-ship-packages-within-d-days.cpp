class Solution {
public:
    bool daysReq(vector<int>& weights, int days, int w) {
        int count = 1;
        int sum = 0;

        for(auto it : weights) {
            sum += it;
            if(sum > w) {
                count++;
                sum = it;
            }
        }

        if(count <= days) {
            return true;
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0, ans = 0;
        int n = weights.size();

        for(int i = 0; i < n; i++) {
            high += weights[i];
        }

        low = *max_element(weights.begin(), weights.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(daysReq(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};