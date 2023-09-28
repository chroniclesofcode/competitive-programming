class Solution {
public:
    const static int MX = 1001;
    #define arr array<int,2>
    int maxtime = 0;
    int ans = 0;
    vector<arr> adj[MX];
    vector<int> q;
    int active[MX];
    void dfs(int u, int quality, int time) {
        if (!active[u]) {
            quality += q[u];
        }
        active[u]++;
        if (u == 0) {
            ans = max(ans, quality);
        }
        for (auto [v, w] : adj[u]) {
            if (time+w <= maxtime) {
                dfs(v, quality, time+w);
            }
        }
        active[u]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        for (auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        q = values;
        maxtime = maxTime;
        dfs(0, 0, 0);
        return ans;
    }
};
