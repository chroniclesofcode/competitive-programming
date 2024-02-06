class Solution {
public:
    int dp[9][260];
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(), m = seats[0].size();
        int LG = 1 << m;
        vector<int> perms;
        for (int mask = 0; mask < LG; mask++) {
            bool valid = true;
            for (int j = 0; j < m; j++) {
                if ((1<<j)&mask) {
                    if (j > 0 && (1<<(j-1))&mask) {
                        valid = false; break;
                    }
                    if ((1<<(j+1))&mask) {
                        valid = false; break;
                    }
                }
            }
            if (valid) perms.push_back(mask);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int p : perms) {
                bool valid = true;
                for (int j = 0; j < m; j++) {
                    if ((1<<j)&p && seats[i][j] != '.') {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
                if (i == 0) {
                    dp[i][p] = __builtin_popcount(p);
                    ans = max(ans, dp[i][p]);
                    continue;
                }
                
                for (int e : perms) {
                    bool valid = true;
                    for (int j = 0; j < m; j++) {
                        if ((1<<j)&p) {
                            if (j>0 && ((1<<(j-1))&e)) {
                                valid = false; break;
                            }
                            if ((1<<(j+1))&e) {
                                valid = false; break;
                            }
                        }
                    }
                    if (valid) {
                        int pc = __builtin_popcount(p);
                        dp[i][p] = max(dp[i][p], pc + dp[i-1][e]);
                        ans = max(ans, dp[i][p]);
                    }
                }
            }
        }
        return ans;
    }
};
