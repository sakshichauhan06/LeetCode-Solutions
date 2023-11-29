class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        multimap<double, pair<int, int>> mp;
        
        if(k == 1) {
            ans.push_back(1);
            ans.push_back(arr[n - 1]);
            return ans;
        }

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n ; j++) {
                double t = (static_cast<double>(arr[i]) / arr[j]);
                mp.insert(make_pair(t, make_pair(arr[i], arr[j])));
            }
        }
        int count = 0;
        for(auto it : mp) {
            ++count;
            if(count == k) {
                ans.push_back(it.second.first);
                ans.push_back(it.second.second);
                break;
            }
        }

        return ans;
    }
};