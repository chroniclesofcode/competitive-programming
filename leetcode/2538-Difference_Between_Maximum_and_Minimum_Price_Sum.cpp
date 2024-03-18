class Solution {
public:
    const static int MX = (int)1e5 + 1;
    vector<int> adj[MX];
    array<long long,2> stats[MX]; // {largest path, largest path without leaf}
    vector<int> cost;
    long long ans = 0;
    void dfs(int u, int p) {
        // base case: a leaf will only have cost on [0], and empty on [1] since excludes itself
        stats[u] = { static_cast<long long>(cost[u]), 0 };
        for (auto v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            // compare current child longest path with longest UNLEAFED
            // child calculated BEFORE. Then do it the opposite.
            // These paths are guaranteed in different subtrees! Never the
            // same, because the actual setting is done underneath.
            ans = max(ans, stats[v][0] + stats[u][1]);
            ans = max(ans, stats[v][1] + stats[u][0]);
            // If this runs, not a leaf, so add your costs.
            stats[u][0] = max(stats[u][0], stats[v][0] + cost[u]);
            stats[u][1] = max(stats[u][1], stats[v][1] + cost[u]);
        }
    }

    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        cost = price;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        return ans;
    }
};
