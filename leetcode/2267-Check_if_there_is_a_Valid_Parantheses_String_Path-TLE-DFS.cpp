class Solution {
public:
    int n, m;
    bool ans = false;
    vector<vector<int>> dirs = {{1,0}, {0,1}};

    bool check(int i, int j) {
        return i < m && j < n;
    }

    void dfs(int i, int j, vector<vector<char>>& grid, int st) {
        if (grid[i][j] == ')' && st == 0) {
            return;
        }
        if (i == m-1 && j == n-1) {
            if (st == 1) {
                ans = true;
            }
            return;
        }
        if (grid[i][j] == ')') {
            st--;
        } else {
            st++;
        }
        for (int k = 0; k < dirs.size(); k++) {
            int nx = i+dirs[k][0];
            int ny = j+dirs[k][1];
            if (check(nx, ny)) {
                dfs(nx, ny, grid, st);
                if (ans) return;
            }
        }
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (grid[m-1][n-1] != ')') return false;
        dfs(0, 0, grid, 0);
        return ans;
    }
};
