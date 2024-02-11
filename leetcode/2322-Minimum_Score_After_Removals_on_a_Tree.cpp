class Solution {
public:
    static const int MX = 1001;
    vector<int> adj[MX];
    vector<int> nums;
    int run = INT_MAX;
    int ans = INT_MAX;

    int dp(int u, int p, int other, int curr, int dep) {
        int rev = nums[u];
        for (int v : adj[u]) {
            if (v == p) continue;
            rev ^= dp(v, u, other, curr, dep+1);
        }
        int tmp = curr^rev;
        if (dep != 0)
            run = min(run, max({tmp, rev, other}) - min({tmp, rev, other}));
        return rev;
    }

    int dfs(int u, int p) {
        int ret = nums[u];
        for (int v : adj[u]) {
            if (v == p) continue;
            ret ^= dfs(v, u);
        }
        return ret;
    }

    int minimumScore(vector<int>& _nums, vector<vector<int>>& edges) {
        nums = std::move(_nums);
        int n = nums.size();
        for (auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (auto& e : edges) {
            int a = dfs(e[0], e[1]);
            int b = dfs(e[1], e[0]);
            run = INT_MAX;
            dp(e[0], e[1], b, a, 0);
            dp(e[1], e[0], a, b, 0);
            ans = min(ans, run);
        }
        return ans;
    }
};
