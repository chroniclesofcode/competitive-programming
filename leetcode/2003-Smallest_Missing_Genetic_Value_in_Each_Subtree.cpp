class Solution {
public:
    int n;
    vector<int> adj[100001];
    vector<int> nums, par;
    int vis[100002];

    void dfs(int u) {
        vis[nums[u]] = 1;
        for (int v : adj[u]) {
            if (!vis[nums[v]]) dfs(v);
        }
    }

    vector<int> smallestMissingValueSubtree(vector<int>& _par, vector<int>& _nums) {
        nums = std::move(_nums);
        par = std::move(_par);
        n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            if (par[i] != -1)
                adj[par[i]].push_back(i);
        }
        int u = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                u = i; break;
            }
        }
        int lo = 1;
        while (u != -1) {
            dfs(u);
            while (vis[lo]) lo++;
            ans[u] = lo;
            u = par[u];
        }
        return ans;
    }
};

