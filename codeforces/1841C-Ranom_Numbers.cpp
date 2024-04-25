#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prLL_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = (LL)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 101;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;

LL dp[MX][2][6];

void solve() {
    string s;
    cin >> s;
    LL n = s.size();
    reverse(s.begin(), s.end());
    vector<LL> a(n);
    vector<LL> convert = { 0, 1, 10, 100, 1000, 10000 };
    for (LL i = 0; i < n; i++) {
        if (s[i] == 'A') a[i] = 1;
        else if (s[i] == 'B') a[i] = 2;
        else if (s[i] == 'C') a[i] = 3;
        else if (s[i] == 'D') a[i] = 4;
        else if (s[i] == 'E') a[i] = 5;
        for (int j = 1; j <= 5; j++) {
            dp[i][0][j] = 0;
            dp[i][1][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 5; j++) {
        }
    }
    LL ans = 0;
    for (int i = 1; i <= 5; i++) {
        ans = max(ans, dp[n-1][0][i]);
        ans = max(ans, dp[n-1][1][i]);
    }
    cout << ans << '\n';

/*
   for each element, what is the value if we
   change the current element to X? you need
   to keep an array of the occurrences so far
   of each element, and keep adding to it.
   If you change it to something, you need
   to jump back and re-calc everything ->
   aka - 2 times the elements smaller.

   You also need to know the elements bigger
   ahead, so use a prefix sum array I suppose
   to find out.
*/

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/
