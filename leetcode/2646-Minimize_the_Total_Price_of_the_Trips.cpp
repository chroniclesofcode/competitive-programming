class Solution {
public:
    int adj[51][51];
    int dp[51][2];
    int ct[51];
    int n;
    int flag = false;
    int tot = 0;
    vector<int> price;
    void dfs(int u, int p, int dest) {
        if (u == dest) {
            flag = true;
            ct[u]++;
            return;
        }
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && v != p) {
                dfs(v, u, dest);
                if (flag) {
                    ct[u]++;
                    return;
                }
            }
        }
    }
    void calc(int u, int p) {
        tot += ct[u] * price[u];
        int take = (ct[u] * price[u])/2;
        int nottake = 0;
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && v != p) {
                calc(v, u);
                take += dp[v][0];
                nottake += max(dp[v][0], dp[v][1]);
            }
        }
        dp[u][1] = take;
        dp[u][0] = nottake;
    }
    int minimumTotalPrice(int _n, vector<vector<int>>& edges, vector<int>& _price, vector<vector<int>>& trips) {
        /*
        count how many times every node is used in a trip. Sort by times * value,
        forcefully halve them.
        */
        n = _n;
        price = _price;
        for (auto e : edges) {
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
        }
        for (auto t : trips) {
            flag = false;
            dfs(t[0], t[0], t[1]);
        }
        calc(0, 0);
        return tot - max(dp[0][0], dp[0][1]);
    }
};

