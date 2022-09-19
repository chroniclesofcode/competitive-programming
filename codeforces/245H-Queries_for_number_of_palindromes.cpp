#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

void solve() {  
    string s;
    cin >> s;

    // Process DP arrays
    int n = s.length();

    vector<vector<int>> pal(n+1, vector<int>(n+1, 0));
    vector<vector<int>> dp(n+1, vector<int>(n, 0));

    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                pal[i][j] = 1;
                dp[i][j] = 1;
            } else if (s[i] == s[j]) {
                if (j-i == 1) {
                    pal[i][j] = true;
                } else {
                    pal[i][j] = pal[i+1][j-1];
                }
            }
        }
    }
    
    // i is length of our substring
    // j is the beginning of where substring is from
    // We use inclusion exclusion principle to use the
    // strings with a SMALLER length to calculate the ones
    // with a longer length. We subtract the intersection
    // length of the two strings to get rid of the duplicates.
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            dp[j][j+i-1] = dp[j][j+i-2] + dp[j+1][j+i-1] - dp[j+1][j+i-2] + pal[j][j+i-1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << dp[l][r] << '\n';
    }
    
}

