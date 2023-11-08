class Solution {
public:
    static const int MX = (int)1e5 + 1;
    int big;
    vector<int> adj[MX];
    int dep[MX];
    vector<int> m;
    vector<int> nums;
    vector<int> ans;

    void dfs(int u, int p) {
        dep[u] = dep[p]+1;
        int tmp = m[nums[u]];
        for (int i = 1; i <= 50; i++) {
            if (m[i] != -1 && __gcd(nums[u], i) == 1) {
                if (ans[u] == -1 || dep[m[i]] > dep[ans[u]]) {
                    ans[u] = m[i];
                }
            }
        }
        m[nums[u]] = u;
        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
        }
        m[nums[u]] = tmp;
    }
    vector<int> getCoprimes(vector<int>& _nums, vector<vector<int>>& edges) {
        nums = _nums;
        ans = vector<int>(nums.size(), -1);
        m = vector<int>(51, -1);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, 0);
        return ans;
    }
};
