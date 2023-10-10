class Solution {
public:
    #define pp pair<int,int>
    unordered_map<int, unordered_map<int, int>> vis;
    const static int MX = 1000000;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int manhat(pp a, pp b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    bool check(pp a) {
        int x = a.first; int y = a.second;
        return !vis[x][y] && x >= 0 && y >= 0 && x < MX && y < MX;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        const int LIM = 199;
        int sx = source[0], sy = source[1];
        int tx = target[0], ty = target[1];
        pp beg = {sx,sy};
        pp end = {tx, ty};
        for (auto b : blocked) {
            pp add = {b[0], b[1]};
            if (manhat(add, beg) <= LIM || manhat(add, end) <= LIM) {
                vis[b[0]][b[1]] = 1;
            }
        }
        queue<pp> q;
        bool f1 = false, f2 = false;
        q.push(beg);
        while (!q.empty()) {
            pp fr = q.front();
            q.pop();
            if (vis[fr.first][fr.second]) continue;
            if (fr == end) return true;
            if (manhat(fr, beg) == LIM) {
                f1 = true;
                break;
            }
            if (manhat(fr, beg) > LIM) continue;
            vis[fr.first][fr.second] = 1;
            for (int i = 0; i < dirs.size(); i++) {
                int nx = fr.first + dirs[i][0];
                int ny = fr.second + dirs[i][1];
                if (check({nx, ny}))
                    q.push({nx, ny});
            }
        }
        q = queue<pp>();
        q.push(end);
        while (!q.empty()) {
            pp fr = q.front();
            q.pop();
            if (vis[fr.first][fr.second]) continue;
            if (fr == beg) return true;
            if (manhat(fr, end) == LIM)  {
                f2 = true;
                break;
            }
            if (manhat(fr, end) > LIM) continue;
            vis[fr.first][fr.second] = 1;
            for (int i = 0; i < dirs.size(); i++) {
                int nx = fr.first + dirs[i][0];
                int ny = fr.second + dirs[i][1];
                if (check({nx, ny}))
                    q.push({nx, ny});
            }
        }
        return f1 && f2;
    }
};
