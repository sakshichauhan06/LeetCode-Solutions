class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int count = 0, i = 0;
        sort(grades.begin(), grades.end());

        if(n == 2) {
            return 1;
        }

        while(i < n) {
            ++count;
            i = count + i + 1;
        }

        return count;
    }
};