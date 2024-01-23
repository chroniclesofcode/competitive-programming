class Solution {
public:
    int n, m;
    int flag1 = false, flag2 = false;
    int vis[1001][1001];
    vector<vector<int>> g;
    void dfsl(int i, int j) {
        if (!(i >= 0 && j >= 0 && i <= n && j <= m)) return;
        if (i == n && j == m) {
            flag1 = true;
            return;
        }
        if (flag1) return;
        if (vis[i][j]) return;
        
        if (g[i][j] == 0) return;
        vis[i][j] = 1;
        dfsl(i+1,j);
        dfsl(i,j+1);
    }

    void dfsr(int i, int j) {
        if (!(i >= 0 && j >= 0 && i <= n && j <= m)) return;
        if (i == n && j == m) {
            flag2 = true;
            return;
        }
        if (flag2) return;
        if (vis[i][j]) return;
        if (g[i][j] == 0) return;
        vis[i][j] = 1;
        dfsr(i,j+1);
        dfsr(i+1,j);
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size()-1;
        m = grid[0].size()-1;
        if ((m == 0 && n == 0) || (m == 1 && n == 0) || (n == 1 && m == 0)) {
            return false;
        }
        vis[0][0] = 1;
        dfsl(1, 0);
        dfsr(0, 1);
        if (flag1 && flag2) {
            return false;
        }
        return true;
    }
};
