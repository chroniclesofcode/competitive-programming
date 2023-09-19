class Solution {
public: 
    const static int MX = 3*(int)1e4+1;
    int tot = 0;
    int dist[MX], subt[MX];
    vector<int> adj[MX];
    int globN;
    void dfs(int u, int p, int dep) {
        subt[u] = 1;
        tot += dep;
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, dep+1);
                subt[u] += subt[v];
            }
        }
    }
    void dfs2(int u, int p, int dp) {
        int curr = dp + globN - 2*subt[u];
        dist[u] = curr;
        for (int v : adj[u]) {
            if (v != p) {
                dfs2(v, u, curr);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        globN = N;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, 0, 0);
        dist[0] = tot;
        for (int v : adj[0]) {
            dfs2(v, 0, dist[0]);
        }
        vector<int> ret;
        for (int i = 0; i < N; i++) {
            ret.push_back(dist[i]);
        }
        return ret;
    }
};
