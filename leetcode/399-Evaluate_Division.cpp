class Solution {
public:
    vector<pair<int, double>> adj[100];
    double ret = -1.0;
    int vis[30];
    void dfs(double st, int u, int p, int goal) {
        if (vis[u]) return;
        vis[u] = 1;
        if (ret != -1.0) return;
        if (u == goal) {
            ret = st;
            return;
        }
        for (auto &[v, w] : adj[u]) {
            if (v == p) continue;
            dfs(st * w, v, u, goal);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int ct = 1;
        unordered_map<string, int> m;
        for (int i = 0; i < equations.size(); i++) {
            if (m[equations[i][0]] == 0) m[equations[i][0]] = ct++;
            if (m[equations[i][1]] == 0) m[equations[i][1]] = ct++;
            adj[m[equations[i][0]]].push_back({m[equations[i][1]], values[i]});
            adj[m[equations[i][1]]].push_back({m[equations[i][0]], 1/values[i]});
        }
        vector<double> ans;
        for (auto &q : queries) {
            int c = m[q[0]], d = m[q[1]];
            if (d == 0 || c == 0) {
                ans.push_back(-1.0);
                continue;
            }
            ret = -1.0;
            memset(vis, 0, sizeof(vis));
            dfs(1.0, c, 0, d);
            ans.push_back(ret);
        }
        return ans;
    }
};
