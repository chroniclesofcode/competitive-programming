class Solution {
public:
    int vis[6005], hit[6005];
    set<int> st;
    unordered_map<int, int> id;
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        for (auto& i : intervals) {
            st.insert(i[0]);
            st.insert(i[1]);
        }
        int ct = 1;
        for (auto it : st) {
            id[it] = ct++;
        }
        vector<array<int,2>> iv;
        int sz = 0;
        for (auto &i : intervals) {
            int u = id[i[0]], v = id[i[1]];
            iv.push_back({v, u});
        }
        sort(iv.begin(), iv.end());
        int ans = 0;
        for (int i = 0; i < iv.size(); i++) {
            if (vis[i] >= 2) continue;
            int u = iv[i][1], v = iv[i][0];
            if (vis[i] < 2 && !hit[v]) {
                for (int j = 0; j < iv.size(); j++) {
                    if (i == j) continue;
                    if (vis[j] >= 2) continue;
                    if (iv[j][1] <= v && v <= iv[j][0]) {
                        vis[j]++;
                    }
                }
                ans++;
                vis[i]++;
                hit[v] = 1;
            }
            if (vis[i] < 2 && !hit[v-1]) {
                for (int j = 0; j < iv.size(); j++) {
                    if (i == j) continue;
                    if (vis[j] >= 2) continue;
                    if (iv[j][1] <= v-1 && v-1 <= iv[j][0]) {
                        vis[j]++;
                    }
                }
                ans++;
                vis[i]++;
                hit[v-1] = 1;
            }
        }
        
        return ans;
    }
};
