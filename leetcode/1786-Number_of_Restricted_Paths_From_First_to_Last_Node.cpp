class Solution {
public:
    #define ll long long
    #define arr array<ll,2>
    vector<arr> adj[5*(int)1e4];
    ll dist[3*(int)1e4];
    bool vis[3*(int)1e4];
    bool vis2[3*(int)1e4];
    long long dp[3*(int)1e4];
    int res = 1;
    const ll MOD = 1e9 + 7;
    void dfs(ll u) {
        dp[u] = u == res ? 1 : 0;
        vis2[u] = 1;
        for (auto& [v, weight] : adj[u]) {
            if (!vis2[v] && dist[u] > dist[v]) {
                dfs(v);
            }
            if (dist[u] > dist[v]) {
                dp[u] += dp[v];
                dp[u] %= MOD;
            }
        }
    }

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        res = n;
        for (auto a : edges) {
            adj[a[0]].push_back({a[1], a[2]});
            adj[a[1]].push_back({a[0], a[2]});
        }
        for (int i = 1; i <= n; i++) {
            dist[i] = numeric_limits<ll>::max();
        }
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        dist[n] = 0;
        pq.push({0, n});
        while (!pq.empty()) {
            arr a = pq.top();
            int u = a[1];
            int w = a[0];
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto &[v, weight] : adj[u]) {
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }
        dfs(1);
        return dp[1];
    }
};
