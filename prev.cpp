class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans;
    vector<int> dp;

    void dfs(int u, int p, vector<int> &g) {
        if (u == p) return;
        int count = 0;
        if (g[u]) count = 1;
        else count = -1;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, g);
            if (dp[v] > 0) {
                count += dp[v];
            }
        }
        dp[u] = count;
    }

    void calc(int u, int p) {
        if (u == p) return;
        ans[u] = dp[u];
        if (p != -1 && (ans[p] > dp[u])) {
            if (dp[u] <= 0) {
                ans[u] += ans[p];
            } else {
                ans[u] += ans[p] - dp[u];
            }
        }
        for (int v : adj[u]) {
            if (v == p) continue;
            calc(v, u);
        }
    }
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        adj = vector<vector<int>>(n, vector<int>());
        dp = vector<int>(n, 0);
        ans = vector<int>(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, good);
        calc(0, -1);
        return ans;
    }
};