class Solution {
public:
    const static int MX = 505;
    int n;
    int c[MX];
    vector<int> adj[MX];
    vector<int> g;
    int vis[MX];
    bool flag = true;
    int ct = 0;
    int bfs(int st) {
        queue<int> q;
        q.push(st);
        int lvl = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front();
                q.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        q.push(v);
                    }
                }
            }
            lvl++;
        }
        return lvl;
    }
    void dfs(int u, int pc) {
        if (flag == false) return;
        c[u] = pc == 1 ? 2 : 1;
        g.push_back(u);
        for (int v : adj[u]) {
            if (c[v] == 0) dfs(v, c[u]);
            else if (c[u] == c[v]) { flag = false; return; }
        }
    }
    int magnificentSets(int _n, vector<vector<int>>& edges) {
        n = _n;
        for (auto &e : edges) {
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] == 0) {
                g.clear();
                dfs(i, 1);
                if (!flag) return -1;
                int b = 0;
                for (int u : g) {
                    for (int v : g) vis[v] = 0;
                    b = max(b, bfs(u));
                }
                ans += b;
            } 
        }
        return ans;
    }
};
