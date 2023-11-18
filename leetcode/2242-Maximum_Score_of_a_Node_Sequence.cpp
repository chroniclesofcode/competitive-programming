class Solution {
public:
    static const int MX = 5 * (int)1e4 + 1;
    vector<int> adj[MX];
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(), [&](const int a, const int b){
                return scores[a] > scores[b];
            });
        }
        int ans = 0;
        for (auto e : edges) {
            int u = e[0], v = e[1];
            for (int i = 0; i < 4 && i < adj[u].size(); i++) {
                for (int j = 0; j < 4 && j < adj[v].size(); j++) {
                    // u edge != v AND u edge != v edge AND u != v edge
                    if (adj[u][i] != v && adj[u][i] != adj[v][j] && u != adj[v][j]) {
                        ans = max(ans, scores[adj[u][i]]+scores[adj[v][j]]+scores[u]+scores[v]);
                    }
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
