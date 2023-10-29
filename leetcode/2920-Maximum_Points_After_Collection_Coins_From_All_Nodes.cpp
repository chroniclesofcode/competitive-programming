class Solution {
public:
    static const int MX = (int)1e5 + 1;
    vector<int> adj[MX];
    int c[MX];
    int dp[MX][22][2];
    int cost;
    void dfs(int u, int p) {
        for (int i = 0; i < 20; i++) {
            dp[u][i][0] = c[u] - cost;
            dp[u][i][1] = c[u]/2;
            c[u] /= 2;
        }
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            for (int i = 0; i < 20; i++) {
                dp[u][i][0] += max(dp[v][i][0], dp[v][i][1]);
                if (i + 1 < 20) {
                    dp[u][i][1] += max(dp[v][i+1][0], dp[v][i+1][1]);
                }
            }
        }
        
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        cost = k;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < coins.size(); i++) c[i] = coins[i];
        dfs(0, 0);
        return max(dp[0][0][0], dp[0][0][1]);
    }
};
