class Solution {
public:
    #define LL long long
    const LL MOD = 1e9 + 7;
    vector<array<LL, 2>> adj[500];
    LL ct[500];
    LL dist[500];
    int countPaths(int n, vector<vector<int>>& roads) {
        for (LL i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        for (LL i = 0; i < n; i++) {
            dist[i] = LLONG_MAX / 2;
        }
        ct[0] = 1;
        dist[0] = 1;
        // time taken, current node, previous
        #define arr array<LL,3>
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto tp = pq.top();
            LL u = tp[1];
            LL time = tp[0];
            LL prev = tp[2];
            pq.pop();
            if (dist[u] < time) {
                continue;
            } else if (dist[u] == time) {
                ct[u] += ct[prev];
                ct[u] %= MOD;
                continue;
            } else {
                ct[u] = ct[prev];
                ct[u] %= MOD;
                dist[u] = time;
            }
            for (auto e : adj[u]) {
                LL v = e[0];
                LL d = e[1];
                if (dist[v] >= dist[u] + d) {
                    pq.push({ dist[u]+d, v, u });
                }
            }
        }
        
        return ct[n-1] % MOD;
    }
};

