class Solution {
public:
    const int static MX = (int)1e5;
    #define LL long long
    LL n, q;
    LL par[MX], grp[MX], tin[MX], tout[MX], depth[MX], comp[MX], pos[MX], sz[MX];
    bool vis[MX];
    vector<LL> adj[MX], cycle;
    LL timer = 0;
    
    void dfs(LL u) {
        tin[u] = ++timer;
        for (LL v : adj[u]) {
            // Since we processed the full cycle before, this
            // makes sure we're not processing an element in
            // the cycle, and just keeping to tree nodes.
            if (comp[v] == v) continue;
            depth[v] = depth[u]+1;
            grp[v] = grp[u];
            comp[v] = comp[u];
            dfs(v);
        }
        tout[u] = ++timer;
    }
    
    vector<int> countVisitedNodes(vector<int>& edges) {
        n = edges.size();
        for (int i = 0; i < edges.size(); i++) {
            par[i] = edges[i];
            adj[par[i]].push_back(i);
        }
        // Initialisations
        for (LL i = 0; i < n; i++) {
            comp[i] = -1;
        }

        // Find cycle
        for (LL i = 0; i < n; i++) {
            if (comp[i] != -1) {
                continue;
            }
            LL u = i;
            // Arrives at cycle
            while (!vis[u]) {
                vis[u] = 1;
                u = par[u];
            }
            LL cycs = u;
            LL ct = 1;
            // Iterates through cycle again, setting values
            while (u != cycs || cycle.empty()) {
                cycle.push_back(u);
                grp[u] = i;
                pos[u] = ct++;
                comp[u] = u; // Note: this holds true if in cycle
                u = par[u];
            }
            LL cycle_size = cycle.size();
            for (auto &c : cycle) {
                timer = 0;
                sz[c] = cycle_size;
                // dfs outwards from each node to the end of 
                // tree, propagating values throughout
                dfs(c);
            }

            cycle.clear();
        }
        vector<int> ans;
        int ret;
        for (int i = 0; i < n; i++) {
            ret = 0;
            if (comp[i] == i) {
                ans.push_back(sz[i]);
            } else {
                ret = depth[i] + sz[comp[i]];
                ans.push_back(ret);
            }
        }
        return ans;
    }
};
