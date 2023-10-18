class Solution {
public:
    #define pp pair<int, int>
    const static int MX = (int)1e4;
    vector<int> adj[MX];
    set<int, greater<int>> dist[MX];
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        for (auto e : edges) {
            int u = e[0]-1; int v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int INF = (int)1e9;
        queue<int> q;
        q.push(0);
        int lvl = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front();
                q.pop();
                if (u == n-1 && dist[u].size() == 2) break;
                if (dist[u].size() == 2) continue;
                dist[u].insert(lvl);
                for (int v : adj[u]) {
                    if (dist[v].size() < 2) {
                        q.push(v);
                    }
                }
            }
            lvl++;
        }
        int ans = *dist[n-1].begin();
        int sol = 0;
        for (int i = 0; i < ans; i++) {
            sol = (sol/change)%2 == 0 ? sol : sol + change - (sol%change);
            sol += time;
        }
        return sol;
    }
};
