class Solution {
public:
    static const long long MX = 2 * (long long)1e4 + 1;
    vector<long long> adj[MX];
    vector<long long> ans;
    vector<long long> cost;
    
    multiset<long long> dfs(long long u, long long p) {
        multiset<long long> s;
        s.insert(cost[u]);
        for (auto v : adj[u]) {
            if (p == v) continue;
            multiset<long long> vs = dfs(v, u);
            if (vs.size() > s.size()) swap(s, vs);
            s.merge(vs);
        }
        ans[u] = 1;
        if (s.size() >= 3) {
            auto it = s.begin();
            long long neg1 = *it++;
            long long neg2 = *it;
            auto it2 = s.rbegin(); it2++;
            long long pos = 1;
            pos *= *it2; it2++; pos *= *it2;
            long long big = *s.rbegin();
            ans[u] = max(big*neg1*neg2, big*pos);
            ans[u] = max((long long)0, ans[u]);
        }
        return std::move(s);
    }
    
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& _cost) {
        cost = vector<long long>(_cost.begin(), _cost.end());
        long long n = cost.size();
        vector<long long> tmp(n, 0);
        ans = tmp;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1);
        return ans;
    }
};

