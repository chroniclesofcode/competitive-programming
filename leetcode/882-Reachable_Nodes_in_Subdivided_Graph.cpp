class Solution {
public:
    static const int mx = 3001;
    vector<array<int,2>> adj[mx];
    int vis[mx];
    int dist[mx];
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        for (auto e : edges) {
            adj[e[1]].push_back({e[0], e[2]+1});
            adj[e[0]].push_back({e[1], e[2]+1});
        }
        int inf = (int)1e9 + 1;
        for (int i = 0; i < n; i++) dist[i] = inf;
        #define arr array<int,2>
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        pq.push({0, 0}); // distance, node
        dist[0] = 0;
        while (!pq.empty()) {
            auto fr = pq.top();
            int u = fr[1], cd = fr[0];
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto &[v, d] : adj[u]) {
                if (cd + d < dist[v]) {
                    dist[v] = cd + d;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) ans++;
        }
        for (auto &e : edges) {
            int da = maxMoves - dist[e[0]];
            int db = maxMoves - dist[e[1]];
            ans += min(e[2], max(da, 0) + max(db, 0));
        }
        return ans;
    }
};
