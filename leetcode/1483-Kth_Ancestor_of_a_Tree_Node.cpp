class TreeAncestor {
public:
    static constexpr int MX = 5 * (int)1e4 + 1;
    int LG = 1;
    vector<int> adj[MX];
    int up[MX][19];
    void dfs(int u, int p) {
        if (p != u) {
            up[u][0] = p;
            for (int i = 1; i < LG; i++) {
                int val = up[up[u][i-1]][i-1];
                if (val == -1) break;
                up[u][i] = val;
            }
        }
        for (int v : adj[u]) {
            dfs(v, u);
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        for (int i = 1; i < parent.size(); i++) {
            adj[parent[i]].push_back(i);
        }
        while ((1 << LG) <= n) {
            LG++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < LG; j++) {
                up[i][j] = -1;
            }
        }
        dfs(0, 0);
    }
    
    int getKthAncestor(int node, int k) {
        int ans = node;
        for (int i = 0; i < LG; i++) {
            if (k & (1 << i)) {
                if (up[ans][i] == -1) return -1;
                ans = up[ans][i];
            }
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
