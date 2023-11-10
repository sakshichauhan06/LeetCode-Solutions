bool validDist(vector<int>& stalls, int k, int mid) {
    int count = 1;
    int n = stalls.size();
    int lastStall = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastStall >= mid) {
            count++;
            lastStall = stalls[i];
        }
    }

    return (count >= k);
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int ans = 0;
    sort(stalls.begin(), stalls.end());
    int low = 0;
    int high = stalls.back() - stalls.front();

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(validDist(stalls, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}