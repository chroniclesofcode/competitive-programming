class Solution {
public: 
    static const int MX = (int)1e5 + 1;
    vector<int> adj[MX];
    int seen[MX], active[MX], vis[MX], rec[MX][26];
    vector<int> order;
    int n;
    bool hasCycle(int u) {
        if (seen[u]) return false;
        seen[u] = 1;
        active[u] = 1;
        for (int v : adj[u]) {
            if (active[v] || hasCycle(v)) {
                return true;
            }
        }
        active[u] = 0;
        return false;
    }

    void topsort(int u) {
        if (seen[u]) return;
        seen[u] = 1;
        for (int v : adj[u]) {
            topsort(v);
        }
        order.push_back(u);
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        n = colors.size();
        for (int i = 0; i < n; i++) {
            if (!seen[i] && hasCycle(i)) {
                return -1;
            }
        }
        memset(seen, 0, n * sizeof(int));
        for (int i = 0; i < n; i++) {
            if (!seen[i]) topsort(i);
        }
        int ans = 0;
        for (auto o : order) {
            for (auto v : adj[o]) {
                for (int i = 0; i < 26; i++) {
                    rec[o][i] = max(rec[o][i], rec[v][i]);
                }
            }
            rec[o][colors[o]-'a']++;
            ans = max(ans, rec[o][colors[o]-'a']);
        }
        return ans;
    }
};
