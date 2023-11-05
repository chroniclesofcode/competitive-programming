class Solution {
public:
    #define LL long long
    static const LL MX = 2 * (LL)1e4 + 1;
    LL n;
    vector<LL> adj[MX];
    LL subt[MX], res[MX];
    long long ans = 0;
    vector<int> val;
    
    void dfs(LL u, LL p) {
        LL second = val[u];
        subt[u] = val[u];
        LL ct = 0;
        for (LL v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            ct += subt[v];
            second += res[v];
        }
        if (ct == 0) {
            res[u] = 0;
            return;
        }
        subt[u] += ct;
        LL candidate = subt[u] - val[u];
        res[u] = max(candidate, second);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        n = values.size();
        val = values;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, 0);
        return res[0];
    }
};

