class Solution {
public:
    vector<int> ans;
    int seen[(int)1e4+1];
    int vis[(int)1e4 + 1];
    bool term[(int)1e4 + 1];
    bool dfs(vector<vector<int>>& graph, int u) {
        if (vis[u]) return false;
        if (seen[u]) return term[u];
        vis[u] = 1;
        seen[u] = 1;

        bool res = true;
        for (auto v : graph[u]) {
            res = res && dfs(graph, v);
        }
        term[u] = res;
        vis[u] = 0;
        return res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); i++) {
            if (!seen[i]) {
                dfs(graph, i);
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            if (term[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
