class Solution {
public:
    bool validSplits(vector<int>& quantities, int n, int mid) {
        int len = quantities.size();
        int count = 0;
        int i = 0;
        int k = quantities[i];

        while(i < len) {
            if(k >= mid) {
                k -= mid;
                count++;
            } else if(k > 0 && k < mid) {
                k = 0;
                count++;
            } 
            if(k == 0) {
                i++;
                if(i < len) {
                    k = quantities[i];
                }
            }
        }

        // cout<<count<<" ";

        return (count <= n);
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int len = quantities.size();
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(validSplits(quantities, n, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};