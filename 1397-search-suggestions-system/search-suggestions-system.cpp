class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = products.size();
        int len = searchWord.size();
        vector<vector<string>> ans;

        for(int i = 0; i < len; i++) {
            vector<string> temp;
            string prefix = searchWord.substr(0, i + 1);
            int idx = lower_bound(products.begin(), products.end(), prefix) - products.begin();
            int j = idx;
            int count = 0;
            
            while(j < n && count < 3) {
                string cur = products[j].substr(0, i + 1);
                if(cur != prefix) {
                    break;
                }
                temp.push_back(products[j]);
                j++;
                count++;
            }

            ans.push_back(temp);
        }

        return ans;

    }
};