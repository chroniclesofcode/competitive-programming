class Solution {
public:
    int n, m;
    char g[31][31];
    int ck[27];
    int sz = 0;
    int res = 0;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    int ans = INT_MAX;
    void bfs(int x, int y, int cd) {
        if (sz == res) {
            ans = min(ans, cd);
            return;
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<array<int,3>> q;
        q.push({x, y, cd});
        while (!q.empty()) {
            auto fr = q.front();
            int cx = fr[0], cy = fr[1], nowd = fr[2];
            q.pop();
            if (vis[cx][cy]) continue;
            vis[cx][cy] = 1;
            char cc = g[cx][cy];
            if (isalpha(cc)) {
                if (isupper(cc) && ck[tolower(cc)-'a'] == 0) continue;
                if (islower(cc) && ck[cc-'a'] == 0) {
                    ck[cc-'a'] = 1; 
                    sz++;
                    bfs(cx, cy, nowd);
                    ck[cc-'a'] = 0;
                    sz--;
                }
            }
            for (auto &d : dirs) {
                int nx = cx + d[0], ny = cy + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && g[nx][ny] != '#') {
                    q.push({nx,ny,nowd+1});
                }
            }
        }
    }
    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size(), m = grid[0].size();
        array<int,2> beg;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = grid[i][j];
                g[i][j] = c;
                if (isalpha(c) && islower(c)) res++;
                if (c == '@') beg = {i, j};
            }
        }
        bfs(beg[0], beg[1], 0);
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
bfs backtrack until you hit all the keys.
on each new bfs you will have a new vis
array, and a new keys array that is passed
onto you.
dont forget to check wall and empty space.
*/
