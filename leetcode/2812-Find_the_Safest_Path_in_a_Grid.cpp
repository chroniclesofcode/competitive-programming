class Solution {
public:
    #define INF 99999999
    #define arr array<int,2>
    vector<vector<int>> dp = vector<vector<int>>(500, vector<int>(500,INF));
    vector<vector<bool>> vdp = vector<vector<bool>>(500, vector<bool>(500,false));
    int n;
    bool check(int x, int y, int lim) {
        return x < n && y < n && x >= 0 && y >= 0 && dp[x][y] > lim && !vdp[x][y];
    }
    bool check2(int x, int y, int val, vector<vector<bool>> &seen) {
        return x < n && y < n && x >= 0 && y >= 0 && dp[x][y] >= val && !seen[x][y];
    }
    bool bfs(int val) {
        if (dp[0][0] < val) {
            return false;
        }
        vector<vector<bool>> vis(n+1, vector<bool>(n+1, false));
        queue<arr> q;
        q.push({0, 0});
        while (!q.empty()) {
            arr fr = q.front();
            q.pop();
            int x = fr[0];
            int y = fr[1];
            if (vis[x][y]) {
                continue;
            }
            if (x == n-1 && y == n-1) {
                return true;
            }
            vis[x][y] = true;
            if (check2(x+1,y,val, vis)) {
                q.push({x+1,y});
            }
            if (check2(x-1,y,val, vis)) {
                q.push({x-1,y});
            }
            if (check2(x,y+1,val, vis)) {
                q.push({x,y+1});
            }
            if (check2(x,y-1,val, vis)) {
                q.push({x,y-1});
            }
            
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        /*
            multi source bfs to find greatest safety for each square
            then binary search for a bfs that reaches n-1
            be careful on multi-source bfs, add all thieves at once
            don't iterate through thieves one at a time
        */
        
        n = grid.size();
        
        vector<arr> thieves;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    thieves.push_back({i, j});
                }
            }
        }
        queue<array<int,3>> q;
        int mx = 0;
        for (arr e : thieves) {
            q.push({e[0],e[1],0});
        }
        while (!q.empty()) {
            array<int,3> u = q.front();
            q.pop();
            int x = u[0];
            int y = u[1];
            int w = u[2];
            if (vdp[x][y]) {
                continue;
            }
            vdp[x][y] = true;
            dp[x][y] = min(dp[x][y], w);
            mx = max(mx, dp[x][y]);
            if (check(x+1, y, w+1)) {
                q.push({x+1,y,w+1});
            }
            if (check(x-1, y, w+1)) {
                q.push({x-1,y,w+1});
            }
            if (check(x, y+1, w+1)) {
                q.push({x,y+1,w+1});
            }
            if (check(x, y-1, w+1)) {
                q.push({x,y-1,w+1});
            }
        }
        
        
        
        int lo = 0;
        int hi = mx;
        int ans = lo;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            // returns possible or not
            bool res = bfs(mid);
            if (res) {
                ans = max(ans, mid);
                lo = mid+1;
            } else {
                hi = mid-1;
            }
            
            
        }
 
        
        return ans;
    }
};
