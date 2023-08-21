class Solution {
public:
    int n;
    vector<array<int,2>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    bool check(vector<vector<int>>& grid, vector<vector<int>> &vis, int x, int y, int lim) {
        return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && grid[x][y] <= lim;
    }
    bool bfs(vector<vector<int>>& grid, int lim) {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<array<int,2>> q;
        if (grid[0][0] <= lim) {
            q.push({0, 0});
        }
        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();
            if (x == n-1 && y == n-1) {
                return true;
            }
            if (vis[x][y]) {
                continue;
            }
            vis[x][y] = 1;
            for (int i = 0; i < dirs.size(); i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (check(grid, vis, nx, ny, lim)) {
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int lo = 0;
        int hi = n*n - 1;
        int ans = INT_MAX;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            bool val = bfs(grid, mid);
            if (val) {
                ans = min(ans, mid);
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }
};
