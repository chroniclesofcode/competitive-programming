class Solution {
public:
    int timer = 1;
    int vis[31][31];
    int seen[99999];
    int low[99999];
    int tin[99999];
    int sz[99999];
    int grp[99999]; 

    int Find(int a) {
        if (a == grp[a]) {
            return a;
        }
        return grp[a] = Find(grp[a]);
    }

    void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            if (sz[a] < sz[b]) {
                swap(a, b);
            }
            grp[b] = a;
            sz[a] += sz[b];
        }

    }
    vector<int> adj[99999];
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int ans = 0;

    void dfs(int u, int p = -1) {
        seen[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;
        for (int to : adj[u]) {
            if (to == p) continue;
            if (seen[to]) {
                low[u] = min(low[u], tin[to]);
            } else {
                dfs(to, u);
                low[u] = min(low[u], low[to]);
                if (low[to] >= tin[u] && p!=-1)
                    ans++;
                ++children;
            }
        }
        if(p == -1 && children > 1)
            ans++;
    }
    int minDays(vector<vector<int>>& grid) {
        int a = 0, b = 0, val = 0;
        int small = 5;
        int tot = 0, spaces = 0;
        int total = grid.size() * grid[0].size();
        for (int i = 0; i <= total; i++) {
            tin[i] = -1; low[i] = -1;
            grp[i] = i; sz[i] = 1;
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int curr = i * grid[0].size() + j;
                spaces++;
                if (!grid[i][j]) continue;
                tot++;
                for (int k = 0; k < dirs.size(); k++) {
                    int nx = i + dirs[k][0];
                    int ny = j + dirs[k][1];
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny]) {
                        if (!vis[nx][ny]) {
                            int node = nx * grid[0].size() + ny;
                            adj[curr].push_back(node);
                            adj[node].push_back(curr);
                            Union(curr, node);
                            a = nx; b = ny;
                            val = node;
                        }
                    }
                }
                vis[i][j] = 1;
            }
        }
        if (tot == 0) return 0;
        if (tot == 1) return 1;
        if (spaces == tot) {
            if (tot == 2) return 2;
            if (tot == 1) return 1;
            if (grid.size() == 1 || grid[0].size() == 1) return 1;
            return 2;
        }

        dfs(val, -1);
        if (sz[Find(val)] != tot) return 0;
        return ans > 0 ? 1 : 2;
    }
};



