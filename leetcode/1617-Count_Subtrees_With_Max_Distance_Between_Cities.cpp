class Solution {
public:
    static const int MX = (int)20;
    int fw[MX][MX];
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        int LG = 1 << (n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fw[i][j] = (int)1e9;
            }  
        }
        for (auto e : edges) {
            int u = e[0]-1, v = e[1]-1;
            fw[u][v] = 1;
            fw[v][u] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    fw[j][k] = min(fw[j][k], fw[j][i] + fw[i][k]);
                }
            }
        }
        vector<int> ans(n-1);
        for (int i = 0; i < LG; i++) {
            int flag = true;
            int md = 0;
            if (__builtin_popcount(i) == 1) continue;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    queue<int> q;
                    int vis = 0;
                    q.push(j);
                    while (!q.empty()) {
                        int fr = q.front();
                        q.pop();
                        if (vis & (1 << fr)) continue;
                        vis |= 1 << fr;
                        for (int k = 0; k < n; k++) {
                            if (i & (1<<k) && fr != k) {
                                if (fw[fr][k] == 1) q.push(k);
                            }
                        }
                    }
                    if (i != vis) flag = false;
                    break;
                }
            }
            if (flag) {
                for (int j = 0; j < n; j++) {
                    for (int k = j+1; k < n; k++) {
                        if ((i & (1<<j)) && (i & (1<<k))) {
                            md = max(md, fw[j][k]);
                        }
                    }
                }
                if (md > 0) ans[md-1]++;
            }
        }
        return ans;
    }
};
