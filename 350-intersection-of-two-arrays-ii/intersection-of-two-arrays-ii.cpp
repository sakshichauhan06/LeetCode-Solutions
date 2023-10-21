class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> frequency;
        vector<int> result;

        // Count the frequency of elements in nums1
        for (int num : nums1) {
            frequency[num]++;
        }

        // Check for common elements in nums2 and decrement frequency
        for (int num : nums2) {
            if (frequency.find(num) != frequency.end() && frequency[num] > 0) {
                result.push_back(num);
                frequency[num]--;
            }
        }

        return result;
    }
};
