class Solution {
public:
    #define pp pair<int,int>
    const static int MX = (int)1e5;
    vector<int> adj[MX], rev[MX];
    int in[MX], dist[MX];
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        for (auto& rel : relations) {
            adj[rel[0]-1].push_back(rel[1]-1);
            rev[rel[1]-1].push_back(rel[0]-1);
            in[rel[1]-1]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) q.push({i});
        }

        int ans = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                in[v]--;
                if (in[v] == 0) {
                    q.push(v);
                }
            }

            for (int v : rev[u]) {
                dist[u] = max(dist[u], dist[v]);
            }
            dist[u] += time[u];
            ans = max(ans, dist[u]);
        }
        return ans;
    }
};
