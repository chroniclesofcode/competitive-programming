class Solution {
public:
    const static int MX = (int)1e5 + 1;
    int grp[MX], sz[MX], vis[MX];
    vector<int> adj[MX];
    int Find(int a) {
        if (grp[a] == a) return a;
        return grp[a] = Find(grp[a]);
    }
    void Union(int a, int b) {
        a = Find(a); b = Find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        grp[b] = a;
        sz[a] += sz[b];
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            grp[i] = i; sz[i] = 1;
            if (nums[i] == 1) return false;
            maxi = max(maxi, nums[i]);
        }
        vector<bool> isp(MX, true);
        vector<int> ps;
        isp[0] = isp[1] = false;
        for (int i = 2; i <= maxi; i++) {
            if (isp[i]) {
                ps.push_back(i);
                if ((long long)i*i <= n) {
                    for (int j = i*i; j <= n; j += i) {
                        isp[j] = false;
                    }
                }
            }
        }
        unordered_map<int, int> prime;
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            for (int j : ps) {
                if ((long long)j*j > tmp) break;
                if (isp[j] && tmp % j == 0) {
                    if (prime[j] > 0) {
                        adj[prime[j]-1].push_back(i);
                        adj[i].push_back(prime[j]-1);
                    } else {
                        prime[j] = i+1;
                    }
                    while (tmp % j == 0) {
                        tmp /= j;
                    }
                }
            }
            if (tmp > 1 && prime[tmp] == 0) {
                prime[tmp] = i+1;
            } else if (tmp > 1) {
                adj[prime[tmp]-1].push_back(i);
                adj[i].push_back(prime[tmp]-1);
            }
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 1;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                    Union(u, v);
                }
            }
        }
        return sz[Find(0)] == n;
    }
};
