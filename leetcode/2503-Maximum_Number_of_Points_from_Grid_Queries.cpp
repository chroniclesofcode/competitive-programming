class Solution {
public:
    int n, m;
    const static int MX = (int)1e4 + 1;
    int tot = 0;
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    int vis[1001][1001];
    bool check(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y];
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n = grid.size();
        m = grid[0].size();
        vector<int> ret(queries.size(), 0);
        #define arr array<int,3>
        vector<pair<int,int>> redone;
        for (int i = 0; i < queries.size(); i++) {
            redone.push_back({queries[i], i});
        }
        sort(redone.begin(), redone.end());
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        pq.push({grid[0][0], 0, 0});
        for (int i = 0; i < redone.size(); i++) {
            int query = redone[i].first;
            int idx = redone[i].second;
            while (!pq.empty()) {
                arr f = pq.top();
                if (f[0] >= query) break;
                pq.pop();
                int w = f[0];
                int x = f[1]; int y = f[2];
                if (vis[x][y]) continue;
                vis[x][y] = 1;
                tot++;
                for (int j = 0; j < dirs.size(); j++) {
                    int nx = x + dirs[j][0];
                    int ny = y + dirs[j][1];
                    if (check(nx, ny)) {
                        pq.push({grid[nx][ny], nx, ny});
                    }
                }
            }
            ret[idx] = tot;
        }
        return ret;
    }
};
