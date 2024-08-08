class Solution {
public:
    vector<vector<int>> g;
    int n, m;
    int c[15];
    int ans = 0;
    void rec(int st, int ct, int lim) {
        if (ct == lim) {
            int res = 0;
            for (int i = 0; i < m; i++) {
                bool flag = true;
                for (int j = 0; j < n; j++) {
                    if (g[i][j] == 1 && !c[j]) {
                        flag = false; break;
                    }
                }
                if (flag) {
                    res++;
                }
            }
            ans = max(ans, res);
            return;
        }
        if (st >= n) return;
        c[st]++;
        rec(st+1, ct+1, lim);
        c[st]--;
        rec(st+1, ct, lim);
    }

    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        g = std::move(matrix);
        m = g.size(), n = g[0].size();
        rec(0, 0, numSelect);
        return ans;
    }
};
