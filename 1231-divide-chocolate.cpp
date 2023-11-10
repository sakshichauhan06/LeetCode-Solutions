#include <bits/stdc++.h> 
using namespace std;

bool splitsReq(vector<int> &arr, int k, int psum) {
    int sum = 0, count = 0;

    for(auto it : arr) {
        sum += it;
        if(sum >= psum) {
            count++;
            sum = 0;
        }
    }
    return (count >= (k + 1));
}

int getMaximumSweetness(vector<int> &arr, int k)
{
    // Write your code here.
    int high = 0, low = 0, ans = 0;
    for(auto it : arr) {
        high += it;
    }
    low = *min_element(arr.begin(), arr.end());

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(splitsReq(arr, k, mid)) {
            ans = mid;
            low = mid + 1;;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
