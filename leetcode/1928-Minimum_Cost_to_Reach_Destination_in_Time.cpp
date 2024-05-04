class Solution {
public:
    #define arr2 array<int,2>
    #define arr3 array<int,3>
    const static int MX = 1001;
    vector<arr2> adj[MX];

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        int mt = maxTime;
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int ans = INT_MAX;
        int inf = (int)1e9;
        priority_queue<arr3,vector<arr3>,greater<arr3>> q;
        q.push({0, fees[0], 0});
        vector<int> c(n+1, INT_MAX);
        while (!q.empty()) {
            auto fr = q.top();
            auto &[time, cost, u] = fr;
            q.pop();
            if (time > mt) continue;
            if (c[u] <= cost) continue;
            c[u] = cost;
            if (u == n-1) {
                ans = min(ans, c[u]);
                continue;
            }
            for (auto &[v, weight] : adj[u]) {
                if (u == v) continue;
                q.push({time+weight, cost+fees[v], v});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};