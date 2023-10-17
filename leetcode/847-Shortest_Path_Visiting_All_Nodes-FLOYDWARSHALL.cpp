class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int LG = 1 << n;
        int INF = (int)1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        vector<vector<int>> dp(LG, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            dp[1<<i][i] = 0;
            for (int j : graph[i]) {
                dist[i][j] = 1;
            }
        }
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        
        for (int m = 0; m < LG; m++) {
            for (int i = 0; i < n; i++) {
                if (!(m & (1<<i))) {
                    for (int j = 0; j < n; j++) {
                        // i is not visited, j is visited
                        if (m & (1<<j)) {
                            dp[m|(1<<i)][i] = min(dp[m|(1<<i)][i], dp[m][j] + dist[j][i]);
                        }
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++) ans = min(ans, dp[LG-1][i]);
        return ans;
    }
};
