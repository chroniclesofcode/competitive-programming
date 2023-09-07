class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        #define arr array<int,4>
        vector<arr> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], (int)directions[i], i});
        }
        sort(robots.begin(), robots.end());
        int i = 0;
        vector<int> ans;
        vector<array<int,2>> tmp;
        while (i < n && robots[i][2] == 'L') {
            tmp.push_back({robots[i][3], robots[i][1]});
            i++;
        }
        stack<array<int,2>> st; // Only contains R
        for (; i < n; i++) {
            int health = robots[i][1];
            int dir = robots[i][2];
            int idx = robots[i][3];
            if (st.empty() && dir == 'L') {
                tmp.push_back({idx, health});
            } else if (dir == 'R') {
                st.push({health, idx});
            } else if (dir == 'L') {
                while (!st.empty() && health > st.top()[0]) {
                    health--;
                    st.pop();
                }
                if (st.empty()) {
                    tmp.push_back({idx, health});
                } else if (health < st.top()[0]) {
                    auto e = st.top();
                    int top = e[0];
                    int cp = e[1];
                    st.pop();
                    st.push({top-1, cp});
                } else if (health == st.top()[0]) {
                    st.pop();
                }
            }
        }
        
        while (!st.empty()) {
            auto e = st.top();
            st.pop();
            tmp.push_back({e[1], e[0]});
        }
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < tmp.size(); j++) {
            ans.push_back(tmp[j][1]);
        }
        return ans;
    }
};
