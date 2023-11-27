class Solution {
public:
    bool validSeq(string &s1, string &s2, int k) {
        int n1 = s1.size();
        int n2 = s2.size();
        set<string> s;

        for(int i = 0; i <= n1 - k; i++) {
            s.insert(s1.substr(i, k));
        }

        for(int i = 0; i <= n2 - k; i++) {
            if(s.find(s2.substr(i, k)) != s.end()) {
                return true;
            }
        }

        return false;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = 0;
        string s1, s2;

        for(int i = 0; i < n1; i++) {
            s1.push_back(nums1[i] + '0');
        }

        for(int i = 0; i < n2; i++) {
            s2.push_back(nums2[i] + '0');
        }

        int low = 0, high = min(n1, n2);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(validSeq(s1, s2, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};