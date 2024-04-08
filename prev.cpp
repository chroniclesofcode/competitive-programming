class Solution {
public:
    static const int MX = (int)1e5 + 10;
    vector<array<int,2>> adj[MX];
    int sz[MX];
    int grp[MX]; 
    int vis[MX];
    int mincost[MX];
    vector<int> order;
    int run = -1;

    int Find(int a) {
        if (a == grp[a]) {
            return a;
        }
        return grp[a] = Find(grp[a]);
    }

    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            if (sz[a] < sz[b]) {
                swap(a, b);
            }
            grp[b] = a;
            sz[a] += sz[b];
        }

    }
    void dfs(int u) {
        if (vis[u]) return;
        vis[u] = 1;
        for (auto &[v, w] : adj[u]) {
            Union(u, v);
            dfs(v);
            run &= w;
        }
        order.push_back(u);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for (int i = 0; i < n; i++) {
            grp[i] = i; sz[i] = 1;
        }
        vector<int> ans;
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                order.clear();
                run = ~0;
                dfs(i);
                for (auto o : order) {
                    mincost[o] = run;
                }
            }
        }
        for (auto &q : query) {
            if (q[0] == q[1]) {
                ans.push_back(0);
            } else if (Find(q[0]) != Find(q[1])) {
                ans.push_back(-1);
            } else {
                ans.push_back(mincost[q[0]]);
            }
        }
        return ans;
    }
};
