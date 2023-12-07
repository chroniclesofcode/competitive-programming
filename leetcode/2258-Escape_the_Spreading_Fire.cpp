class Solution {
public:
    #define arr array<int,2>
    int dp[301][301], h[301][301];
    int vis[301][301];
    int n, m;
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    inline bool valid(int x, int y) {
      return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && dp[x][y] >= 0;
    }
    int maximumMinutes(vector<vector<int>>& g) {
      int inf = (int)1e9 + 100;
      n = g.size(); m = g[0].size();
      if (n == 1 && m == 1) return 0;
      queue<arr> q; // multisource bfs fire
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
              dp[i][j] = inf;
              if (g[i][j] == 2) {
                  dp[i][j] = -2;
              } else if (g[i][j] == 1) {
                  q.push({i, j});
              }
          }
      }
      int ct = 1;
      while (!q.empty()) {
          int sz = q.size();
          for (int i = 0; i < sz; i++) {
              int fx = q.front()[0], fy = q.front()[1];
              q.pop();
              if (!valid(fx, fy)) continue;
              dp[fx][fy] = ct;
              vis[fx][fy] = 1;
              for (auto d : dirs) {
                int nx = fx + d[0], ny = fy + d[1];
                if (valid(nx, ny)) {
                  q.push({nx, ny});
                }
              }
          }
          ct++;
      }
      memset(vis, 0, sizeof(vis));
      q.push({0,0});
      ct = 1;
      while (!q.empty()) {
          int sz = q.size();
          for (int i = 0; i < sz; i++) {
            int fx = q.front()[0], fy = q.front()[1];
            q.pop();
            if (!valid(fx,fy)) continue;
            if (fx != n-1 && fy != m-1 && dp[fx][fy] <= ct) continue;
            h[fx][fy] = ct;
            vis[fx][fy] = 1;
            for (auto d : dirs) {
              int nx =fx+d[0], ny = fy+d[1];
              if (valid(nx,ny)) {
                q.push({nx,ny});
              }
            }
          }
          ct++;
      }
      if (h[n-1][m-1] == 0) return -1;
      if (h[n-1][m-1] > dp[n-1][m-1]) return -1;
      if (dp[n-1][m-1] >= inf) return (int)1e9;
      int ans = dp[n-1][m-1]-h[n-1][m-1];
      // only -1 when fire and human met earlier, which means adjacent
      // cells have same values, since fire is 'chasing' on every path
      // if not, they met at the destination, so we can wait a liiitle longer
      if (dp[n-1][m-2]-h[n-1][m-2] <= ans && dp[n-2][m-1]-h[n-2][m-1] <= ans) {
        ans--;
      }
      return ans;
    }
};
