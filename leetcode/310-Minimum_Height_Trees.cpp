class Solution {
public:
    vector<int> adj[2*(int)1e4+1];
    bool vis[2*(int)1e4];
    int in[2*(int)1e4];
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for (auto e : edges) {
            int x = e[0];
            int y = e[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
            in[x]++; in[y]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] <= 1) {
                q.push(i);
            }
        }
        int tmp = n;
        while (!q.empty() && tmp > 2) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front();
                q.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                for (int v : adj[u]) {
                    if (vis[v]) continue;
                    in[v]--;
                    if (in[v] <= 1) {
                        q.push(v);
                    }
                }
            }
            tmp -= sz;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};
