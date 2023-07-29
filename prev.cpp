#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL int
void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 110;
//const LL MOD = 1e7;

int n, a[MX], dp[MX][MX], pali[MX][MX];

/*
    Range dp dp[i][j] is time it takes to destroy
    i..j, on each iteration, check if the new value
    creates new palindromes -> O(n^3)
*/

void debug() {
    cout << "\nDEBUG\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << pali[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            dp[i][j] = INF;
            if (i == j) {
                pali[i][j] = 1;
            } else if (a[i] == a[j]) {
                if (j-i <= 1) {
                    pali[i][j] = 1;
                } else {
                    pali[i][j] = pali[i+1][j-1];
                }
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
            dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]);
            for (int k = i; k <= j; k++) {
                if (pali[i][k]) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k+1][j]);
                }
                if (a[i] == a[k] && k - i <= 1) {
                    dp[i][j] = min(dp[i][j], 1+ dp[k+1][j]);
                } else if (a[i] == a[k]) {
                    dp[i][j] = min(dp[i][j], dp[i+1][k-1]+dp[k+1][j]);
                }
            }
        }
    }
    //debug();
    cout << dp[0][n-1] << '\n';
}

