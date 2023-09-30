class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        vector<pair <int, int>> v;
        int a = 0, b = n - 1;

        for(int i = 0; i < n; i++) {
            v.push_back({numbers[i], i});
        }

        sort(v.begin(), v.end());

        while(a < b) {
            int k = v[a].first + v[b].first;
            if(k < target) {
                a++;
            } else if(k > target) {
                b--;
            } else {
                ans.push_back({v[a].second + 1});
                ans.push_back({v[b].second + 1});
                return ans;
            }
        }

        return ans;
    }
};