class Solution {
public:
    int timer = 1;
    vector<vector<int>> ans;
    vector<int> tin, vis, low, adj[(int)1e5];

    void dfs(int u, int p) {
        low[u] = tin[u] = timer++;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    ans.push_back({u, v});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for (auto c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        tin = vector<int>(n, -1);
        vis = vector<int>(n, 0);
        low = vector<int>(n, -1);
        dfs(0, -1);
        return ans;
    }
};
