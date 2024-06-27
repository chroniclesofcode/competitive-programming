class Solution {
public:
    int n, m;
    int dp[4][31][31];
    vector<vector<int>> grid;
    int cover(int sti, int stj, int edi, int edj) {
        if (sti >= n || stj >= m || edi < 0 || edj < 0) return (int)0;
        int x1 = INT_MAX, y1 = INT_MAX;
        int x2 = 0, y2 = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = sti; i <= edi; i++) {
            for (int j = stj; j <= edj; j++) {
                if (grid[i][j] == 1) {
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        if (x1 == INT_MAX) return 0;
        return (abs(x1-x2)+1) * (abs(y1-y2)+1);
    }
    void rotate() {
        vector<vector<int>> rot(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rot[j][n-1-i] = grid[i][j];
            }
        }
        swap(n, m);
        swap(grid, rot);
    }
    int minimumSum(vector<vector<int>>& _grid) {
        grid = std::move(_grid);
        int ans = (int)1e9 + 7;
        n = grid.size(), m = grid[0].size();
        for (int ct = 0; ct < 4; ct++) {
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    ans = min(ans, cover(0,0,i,m-1)+cover(i+1,0,j,m-1)+cover(j+1,0,n-1,m-1));
                }
                for (int j = 0; j < m; j++) {
                    ans = min(ans, cover(0,0,i,j)+cover(0,j+1,i,m-1)+cover(i+1,0,n-1,m-1));
                }
            }
            rotate();
        }
        return ans;
    }
};
