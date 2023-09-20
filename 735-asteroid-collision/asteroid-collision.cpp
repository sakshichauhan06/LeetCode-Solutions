class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> v;

        for(int i = 0; i < n; i++) {
            while(v.size() && asteroids[i] < 0 && v.back() > 0 && abs(asteroids[i]) > v.back()) {
                v.pop_back(); // for the [+, -] condition where -size>+size
            }
            if(v.size() && asteroids[i] < 0) { 
                if(abs(asteroids[i]) == v.back()) { // for those aesteroid of same size but diff directions
                    v.pop_back();
                    continue;
                }
                if(abs(asteroids[i]) < v.back()) { // for the [+, -] condition where -size<+size
                    continue;
                }
            }
            v.push_back(asteroids[i]);
        }

        return v;
    }
};