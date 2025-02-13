class Solution {
public:
    int n;
    vector<int> color;
    vector<vector<int>> adj;
    bool dfs(int u, int c) {
        color[u] = c;
        bool ret = true;
        for (int v : adj[u]) {
            if (color[v] == -1) {
                ret &= dfs(v, !c);
            } else if (color[v] == c) {
                return false;
            }
        }
        return ret;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        color = vector<int>(n, -1);
        adj = graph;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !dfs(i, 0)) return false;
        }
        return true;
    }
};
