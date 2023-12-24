class Solution {
public:
    static constexpr int INF = (int)1e9 + 100;
    long long fw[27][27];
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                fw[i][j] = INF;
            }
            fw[i][i] = 0;
        }
        int n = original.size();
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a'; int v = changed[i] - 'a'; long long c = cost[i];
            fw[u][v] = min(fw[u][v], c);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]) ;
                }
            }
        }

        long long ans = 0;
        n = source.size();
        for (int i = 0; i < n; i++) {
            int u = source[i] - 'a'; int v = target[i] - 'a';
            if (fw[u][v] == INF) {
                return -1;
            }
            ans += fw[u][v];
        }
        return ans;
    }
};
