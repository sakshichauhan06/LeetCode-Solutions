class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 =nums1.size(),n2=nums2.size(),count =0;
        float sum;
        map<int, int> m;
        vector<int> v;
        for(int i=0;i<n1;i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<n2;i++){
           v.push_back(nums2[i]);
        }
       sort(v.begin(),v.end());    
        for(auto i:v){
            count++;
        }
        float n= v.size();
        int start =0, end = n-1;
        float mid =start + (end -start)/2;
        if (count%2==1){
            
            return v[mid];
        }
       
        else if(count%2==0){
           float sum = (float)((v[mid])+(v[mid+1]))/2;
            return sum; 
        }
       
     return {};
    }
};