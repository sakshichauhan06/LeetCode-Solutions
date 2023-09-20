class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> v;

        for(int i = 0; i < n; i++) {
            while(v.size() && asteroids[i] < 0 && v.back() > 0 && abs(asteroids[i]) > v.back()) {
                v.pop_back();
            }
            if(v.size() && asteroids[i] < 0) {
                if(abs(asteroids[i]) == v.back()) {
                    v.pop_back();
                    continue;
                }
                if(abs(asteroids[i]) < v.back()) {
                    continue;
                }
            }
            v.push_back(asteroids[i]);
        }

        return v;
    }
};