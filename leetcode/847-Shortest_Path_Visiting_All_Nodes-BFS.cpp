class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int LG = 1 << n;
        int INF = (int)1e9;
        #define arr array<int,2>
        unordered_map<int, unordered_set<int>> vis;
        queue<arr> q;
        for (int i = 0; i < n; i++) {
            q.push({i, 0}); // node, visited set
        }
        int ct = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int t = 0; t < sz; t++) {
                arr fr = q.front();
                q.pop();
                fr[1] = fr[1] | (1 << fr[0]);
                if (fr[1] == LG-1) {
                    return ct;
                }
                if (vis[fr[1]].count(fr[0])) {
                    continue;
                }
                vis[fr[1]].insert(fr[0]);
                for (int v : graph[fr[0]]) {
                    q.push({v, fr[1]});
                }
            }
            ct++;
        }
        return -1;
    }
};
