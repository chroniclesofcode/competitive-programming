class Solution {
public:
    int timer = 1;
    int vis[31][31];
    int seen[99999];
    int low[99999];
    int tin[99999];
    vector<int> adj[99999];
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int ans = 0;
    int minDays(vector<vector<int>>& grid) {
        int a = 0, b = 0, val = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int curr = i * grid[0].size() + j;
                if (!grid[i][j]) continue;
                for (int k = 0; k < dirs.size(); k++) {
                    int nx = i + dirs[k][0];
                    int ny = j + dirs[k][1];
                    if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] && !vis[nx][ny]) {
                        int node = nx * grid[0].size() + ny;
                        adj[curr].push_back(node);
                        adj[node].push_back(curr);
                        cout << "connected " << i << "," << j << " with " << nx << "," << ny << "\n";
                        a = nx; b = ny;
                        val = node;
                    }
                }
                vis[i][j] = 1;
            }
        }
        if (!grid[a][b]) return 0;
        int tot = grid.size() * grid[0].size();
        for (int i = 0; i <= tot; i++) {
            tin[i] = -1; low[i] = -1;
        }
        dfs(val, -1);
        return ans;
    }
};
