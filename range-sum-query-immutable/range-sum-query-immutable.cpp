class NumArray {
public:
    NumArray(vector<int>& nums) {
        ans.push_back(0);
        int sum = 0;
        for(auto it : nums) {
            sum += it;
            ans.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return (ans[right + 1] - ans[left]);
    }

private:
    vector<int> ans;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */