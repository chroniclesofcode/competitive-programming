class Solution {
public:
    private:
    int n = 0;
    int ans = 0;
    int ret = INT_MAX;
    #define arr2 array<int,2>
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<bool>> vis = vector<vector<bool>>(3, vector<bool>(3, false));

    void dfs(vector<vector<int>>& grid, int numz) {
        if (numz == 0) {
            ret = min(ret, ans);
            return;
        }
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
                vis.assign(n, vector<bool>(n, false));
                queue<arr2> q;
                q.push({i, j});
                bool keeprun = true;
                while (!q.empty()) {
                    int sz = q.size();
                    if (!keeprun) break;
                    for (int z = 0; z < sz; z++) {
                        auto f = q.front();
                        int tx = f[0]; int ty = f[1];
                        q.pop();
                        if (vis[tx][ty]) continue;
                        vis[tx][ty] = true;
                        int adist = abs(tx-i)+abs(ty-j);
                        if (grid[tx][ty] > 1) {
                            keeprun = false;
                            grid[tx][ty]--;
                            grid[i][j]++;
                            ans += adist;
                            
                            dfs(grid, numz-1);

                            ans -= adist;
                            grid[tx][ty]++;
                            grid[i][j]--;
                        }
                        if (!keeprun) continue;
                        for (int k = 0; k < 4; k++) {
                            int nx = tx+dirs[k][0];
                            int ny = ty+dirs[k][1];
                            if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
    }
    public:
    int minimumMoves(vector<vector<int>>& grid) {
        
        n = grid.size();
        int numz = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    numz++;
                }
            }
        }
        dfs(grid, numz);
        return (ret == INT_MAX ? 0 : ret);
    }
};
