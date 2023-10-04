class Solution {
public:
    const static int MX = 60000;
    int in[MX], vis[MX], h[MX];
    vector<int> adj[MX], order;
    vector<vector<int>> dirs = {{0,1,2},{1,0,2}, {2,1,0},{1,2,0},{2,0,1},{0,2,1}};

    void dfs(int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) dfs(v);
        }
        order.push_back(u);
    }

    int maxHeight(vector<vector<int>>& c) {
        int n = c.size();
        vector<vector<int>> cub;
        for (int i = 0; i < n; i++) {
            for (int a = 0; a < dirs.size(); a++) {
                cub.push_back({c[i][dirs[a][0]], c[i][dirs[a][1]], c[i][dirs[a][2]], i});
            }
        }
        n = cub.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (cub[i][3] == cub[j][3]) continue;
                if (cub[i][0] >= cub[j][0] && cub[i][1] >= cub[j][1] && cub[i][2] >= cub[j][2]) {
                    adj[i].push_back(j);
                } else if (cub[i][0] <= cub[j][0] && cub[i][1] <= cub[j][1] && cub[i][2] <= cub[j][2]) {
                    adj[j].push_back(i);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(order.begin(), order.end());
        for (int i = 0; i < order.size(); i++) {
            int u = order[i];
            ans = max(ans, cub[u][2] + h[u]);
            for (int v : adj[u]) {
                h[v] = max(h[v], cub[u][2] + h[u]);
            }
        }
        return ans;
    }
};
