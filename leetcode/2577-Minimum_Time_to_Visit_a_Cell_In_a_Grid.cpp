class Solution {
public:
    int n, m;
    vector<vector<int>> vis, dist;
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    inline bool check(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    int minimumTime(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        vis = vector<vector<int>>(n, vector<int>(m, 0));
        dist = vector<vector<int>>(n, vector<int>(m, 0));
        using arr = array<int,3>;
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            int time = tp[0], x = tp[1], y = tp[2];
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            dist[x][y] = time;
            for (int i = 0; i < dir.size(); i++) {
                int nx = dir[i][0] + x;
                int ny = dir[i][1] + y;
                if (check(nx, ny) && !vis[nx][ny]) {
                    if (time+1 >= grid[nx][ny]) {
                        pq.push({time+1, nx, ny});
                    } else {
                        int diff = grid[nx][ny] - (time+1);
                        diff = diff + (diff % 2) + (time+1);
                        pq.push({diff, nx, ny});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
/*

*/
