class Solution {
public:
    #define arr array<int,2>
    int timer = 1;
    const static int MX = 1e4+1;
    vector<arr> adj[MX];
    int tin[MX], tout[MX], weight[MX][27], dep[MX];
    vector<vector<int>> up;
    int LG;

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;
        if (p != -1) dep[u] = dep[p]+1;

        for (int i = 1; i <= LG; i++) {
            if (up[u][i-1] != -1)
                up[u][i] = up[up[u][i-1]][i-1];
        }
        for (arr e: adj[u]) {
            int v = e[0];
            if (v != p) {
                dfs(v, u);
            }
        }
        tout[u] = ++timer;
    }

    // is v one of the childs of u?
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u,v)) return u;
        if (is_ancestor(v,u)) return v;

        for (int i = LG; i >= 0; i--) {
            if (up[u][i] != -1 && !is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    void calcWeights(int u, int p, int w) {
        for (int i = 0; i < 27; i++) {
            weight[u][i] = weight[p][i];
        }
        weight[u][w]++;
        for (auto e : adj[u]) {
            if (e[0] != p)
                calcWeights(e[0], u, e[1]);
        }
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for (int i = 30; i >= 0; i--) {
            if (n & (1 << i)) {
                LG = i+1;
                break;
            }
        }
         up = vector<vector<int>>(n+1, vector<int>(LG+1, -1));
        for (auto e : edges) {
            int a = e[0];
            int b = e[1];
            int w = e[2];
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        dfs(0, -1);
        for (auto e : adj[0]) {
            calcWeights(e[0], 0, e[1]);
        }
        vector<int> ans;
        for (auto q : queries) {
            int a = q[0];
            int b = q[1];
            int anc = lca(a, b);
            int v1 = 0, v2 = 0;
            int tmp[27] = { 0 };
            int cmx = 0;
            for (int i = 0; i < 27; i++) {
                tmp[i] = weight[a][i] - weight[anc][i];
                tmp[i] += weight[b][i] - weight[anc][i];
                cmx = max(cmx, tmp[i]);
            }
            int quantity = dep[a] + dep[b] - 2*dep[anc];
            ans.push_back(quantity - cmx);
        }

        return ans;
    }
};
