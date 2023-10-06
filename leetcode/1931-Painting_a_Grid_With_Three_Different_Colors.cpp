class Solution {
public:
    long long dp[3000][1001];
    vector<string> combs;
    string tmp;
    void generate(int num, int idx) {
        if (idx == num) {
            combs.push_back(tmp);
            return;
        }
        for (int i = 0; i < 3; i++) {
            char ch = i + '0';
            if (idx == 0 || tmp.back() != ch) {
                tmp.push_back(ch);
                generate(num, idx+1);
                tmp.pop_back();
            }
        }
    }
    int colorTheGrid(int n, int m) {
        // for every column, it is possible to go through
        // every possible combinations of 5 colours
        generate(n, 0);
        int csz = combs.size();
        int MD = (int)1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int l = 0; l < csz; l++) {
                string &c1 = combs[l];
                if (i == 0) {
                    dp[l][i] = 1;
                    continue;
                }
                for (int k = 0; k < csz; k++) {
                    bool eq = true;
                    string &c2 = combs[k];
                    for (int j = 0; j < n; j++) {
                        if (c1[j] == c2[j]) {
                            eq = false;
                            break;
                        }
                    }
                    if (eq) {
                        dp[l][i] += dp[k][i-1];
                        dp[l][i] %= MD;
                    }
                }
            }
        }
        for (int i = 0; i < csz; i++) {
            ans = (ans + dp[i][m-1]) % MD;
        }
        return ans;
    }
};
