class Solution {
public:
    bool exist(vector<int>& bobSizes, int target) {
        int n = bobSizes.size();
        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(bobSizes[mid] == target) {
                return true;
            } else if(bobSizes[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int alice = aliceSizes.size();
        int bob = bobSizes.size();
        int aliceSum = 0, bobSum = 0;
        vector<int> ans;

        for(int i = 0; i < alice; i++) {
            aliceSum += aliceSizes[i];
        }

        for(int i = 0; i < bob; i++) {
            bobSum += bobSizes[i];
        }

        sort(bobSizes.begin(), bobSizes.end());

        for(int i = 0; i < alice; i++) {
            int target = (bobSum - aliceSum + 2 * aliceSizes[i]) / 2;
            if(exist(bobSizes, target)) {
                ans.push_back(aliceSizes[i]);
                ans.push_back(target);
                break;
            }
        }

        return ans;
    }
};