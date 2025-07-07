#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = 998244353;

int n, m, k, q;


void solve() {
    cin >> n >> m;
    string s; 
    cin >> s;
    map<vector<int>, long long> dp;
    vector<int> tmp(n);
    dp[tmp] = 1;
    // for every char in M, what if letter was a-z?
    for (int i = 0; i < m; i++) {
        map<vector<int>, long long> nextdp;
        // go through all previous dp[i]'s. These represent
        // previous states of LIS dps that exist (and count of them)
        for (auto &[prev, ct] : dp) {
            // add a new char onto it. Note: irrespective of prev chars!
            for (int j = 0; j < 26; j++) {
                char c = 'a' + j;
                vector<int> curr = prev;
                // build LCS from scratch, using prev as a starting pt
                for (int k = 0; k < n; k++) {
                    if (s[k] == c) curr[k] = (k ? prev[k-1]+1 : 1);
                    if (k) curr[k] = max(curr[k], curr[k-1]);
                }
                // prev state -> curr state, add all ways to reach prev
                nextdp[curr] = (nextdp[curr] + ct) % MD;
            }
        }
        dp = nextdp;
    }
    // dp now represents counts of all fully built strings of length M
    // well, their DP arrays, that is.
    // grab last elem in array for subseq of length exactly k (LCS)
    // add ways to reach it to ans
    vector<long long> ans(n+1);
    for (auto &[curr, ct] : dp) {
        ans[curr[n-1]] = (ans[curr[n-1]] + ct) % MD;
    }
    for (int i = 0; i < n+1; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
