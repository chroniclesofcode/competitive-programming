class Solution {
public:
    int n;
    int ans = 0;
    int ret = INT_MAX;
    #define arr array<int,2>
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    bool check(int x, int y, vector<vector<bool>>& vis) {
        return x >= 0 && y >= 0 && x < n && y < n && !vis[x][y];
    }
    void dfs(vector<vector<int>>& grid) {
        bool comp = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) {
                    comp = false;
                    break;
                }
            }
        }
        if (comp) {
            ret = min(ret, ans);
            return;
        }
        queue<arr> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
                vector<vector<bool>> vis(n, vector<bool>(n, false));
                q.push({i, j});
                while (!q.empty()) {
                    auto f = q.front();
                    int tx = f[0]; int ty = f[1];
                    q.pop();
                    if (vis[tx][ty]) continue;
                    vis[tx][ty] = true;
                    if (grid[tx][ty] > 1) {
                        grid[tx][ty]--;
                        grid[i][j]++;
                        ans += abs(tx-i)+abs(ty-j);
                        
                        dfs(grid);
                        
                        ans -= abs(tx-i)+abs(ty-j);
                        grid[tx][ty]++;
                        grid[i][j]--;
                    }
                    for (int k = 0; k < 4; k++) {
                        int nx = tx+dirs[k][0];
                        int ny = ty+dirs[k][1];
                        if (check(nx, ny, vis)) {
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    int minimumMoves(vector<vector<int>>& grid) {
        
        n = grid.size();
        dfs(grid);
        return ret;
    }
};
