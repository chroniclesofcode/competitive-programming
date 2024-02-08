class Solution {
public:
    int dp[(int)1e5+1];
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0), col(m, 0);
        map<int, vector<int>> ord;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ord[mat[i][j]].push_back(i*m+j);
            }
        }
        // lowest first
        int ans = 0;
        for (auto& [num, vec] : ord) {
            for (auto e : vec) {
                dp[e] = max(row[e/m], col[e%m]) + 1;
                ans = max(ans, dp[e]);
            }
            for (auto e : vec) {
                row[e/m] = max(row[e/m], dp[e]);
                col[e%m] = max(col[e%m], dp[e]);
            }
        }
        return ans;
    }
};
