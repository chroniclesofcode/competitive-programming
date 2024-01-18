class Solution {
public:
    #define arr array<long long, 2>
    static constexpr long long inf = (long long)1e11 + 10;
    static constexpr int mx = (int)1e5+1;
    vector<long long> dist1, dist2, distd;
    vector<arr> adj[mx];
    vector<arr> rev[mx];
    int vis[mx];
    void dijkstra(vector<array<long long, 2>> g[], vector<long long>& dist, int src) {
        memset(vis, 0, sizeof(vis));
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [d, v] : g[u]) {
                if (dist[v] > w + d) {
                    dist[v] = w + d;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        dist1 = vector<long long>(n, inf);
        dist2 = vector<long long>(n, inf);
        distd = vector<long long>(n, inf);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[2], e[1]});
            rev[e[1]].push_back({e[2], e[0]});
        }
        dijkstra(adj, dist1, src1);
        dijkstra(adj, dist2, src2);
        dijkstra(rev, distd, dest);
        long long ans = dist1[dest] + dist2[dest];
        ans = min(ans, dist1[src2] + dist2[dest]);
        ans = min(ans, dist1[dest] + dist2[src1]);
        for (int i = 0; i < n; i++) {
            ans = min(ans, dist1[i] + dist2[i] + distd[i]);
        }
        return ans >= inf ? -1 : ans;
    }
};
