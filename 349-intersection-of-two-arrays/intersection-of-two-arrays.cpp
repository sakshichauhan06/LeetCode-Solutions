class Solution {
public:
    int binSearch(vector<int>& v2, int target) {
        int n = v2.size();
        int l = 0, h = n - 1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(v2[mid] == target) {
                return target;
            } else if(v2[mid] < target) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return -1;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1, s2;
        for(auto it : nums1) {
            s1.insert(it);
        }
        for(auto it : nums2) {
            s2.insert(it);
        }
        vector<int> v1, v2;
        copy(s1.begin(), s1.end(), back_inserter(v1));
        copy(s2.begin(), s2.end(), back_inserter(v2));
        
        vector<int> ans;

        for(int i = 0; i < v1.size(); i++) {
            int k = binSearch(v2, v1[i]);
            if(k != -1) {
                ans.push_back(k);
            }
        }

        return ans;
    }
};