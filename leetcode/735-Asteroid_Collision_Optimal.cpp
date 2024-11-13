class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (int a : asteroids) {
            if (a > 0 || s.empty() || s.back() < 0) {
                s.push_back(a);
                continue;
            }
            while (!s.empty() && s.back() > 0 && s.back() < -a) {
                s.pop_back();
            }
            if (s.empty() || s.back() < -a) {
                s.push_back(a);
            } else if (s.back() == -a) {
                s.pop_back();
            }
        }
        return s;
    }
};
