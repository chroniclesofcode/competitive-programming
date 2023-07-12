class Solution {
public:
    // leftmost negs and rightmost pos never meet anything
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        deque<int> q;
        for (auto &a : asteroids) {
            if (q.empty()) {
                q.push_back(a);
                continue;
            } 
            if (a > 0) {
                q.push_back(a);
            } else {
                while (!q.empty() && q.back() > 0 && q.back() < abs(a)) {
                    q.pop_back();
                }
                if (q.empty() || q.back() < 0) {
                    q.push_back(a);
                } else {
                    if (q.back() == abs(a)) {
                        q.pop_back();
                    }
                }
            }
        }

        for (auto &e : q) {
            ans.push_back(e);
        }
        return ans;
    }
};
