class Solution {
public:
    int dp[101][101];
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    dp[i][j] = matrix[i][j];
                } else {
                    dp[i][j] = dp[i-1][j] + matrix[i][j];
                }
            }
        }
        int ans = 0;
        unordered_map<int,int> ct;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                ct.clear();
                ct[0] = 1;
                int p = 0;
                for (int k = 0; k < m; k++) {
                    int val = j == 0 ? dp[i][k] : dp[i][k] - dp[j-1][k];
                    p += val;
                    if (ct[p-target] > 0) ans += ct[p-target];
                    ct[p]++;
                }
                cout << endl;
            }
        }
        return ans;
    }
};
