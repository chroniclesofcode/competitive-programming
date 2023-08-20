class Solution {
public:
    unordered_map<int,unordered_set<int>> adj;
    unordered_map<int, int> vis;
    unordered_map<int, int> stopvis;
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        for (int i = 0; i < routes.size(); i++) {
            for (auto stop : routes[i]) {
                adj[stop].insert(i);
            }
        }
        int ans = -1;
        #define arr array<int,2>
        queue<arr> q;
        for (auto it = adj[source].begin(); it != adj[source].end(); it++)  {
            q.push({*it, 1});
        }
        while (!q.empty()) {
            int bus = q.front()[0];
            int ct = q.front()[1];
            q.pop();
            if (adj[target].count(bus)) {
                return ct;
            }
            if (vis[bus]) {
                continue;
            }
            vis[bus] = 1;
            for (int stop : routes[bus]) {
                if (stopvis[stop]) {
                    continue;
                }
                stopvis[stop] = 1;
                for (auto it = adj[stop].begin(); it != adj[stop].end(); it++) {
                    // *it = the buses
                    if (!vis[*it]) {
                        q.push({*it, ct+1});
                    }
                }
            }
        }

        return -1;
    }
};
