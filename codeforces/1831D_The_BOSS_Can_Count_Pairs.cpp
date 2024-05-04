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
constexpr LL MX = 2 * 1e5 + 10;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;
array<int,2> a[MX];
array<int,3> b[MX];
int fr[635][MX];

void solve() {
    cin >> n;
    LL lim = sqrt(2*n);
    LL tm;
    for (LL i = 0; i < n; i++) { cin >> tm; a[i][0] = tm; }
    for (LL i = 0; i < n; i++) { 
        cin >> tm; 
        a[i][1] = tm;
        if (a[i][0] <= lim) fr[a[i][0]][a[i][1]]++;
    }
    LL ans = 0;
    sort(a, a+n);
    int sz = 0;
    int run = 1;
    for (LL i = 1; i < n; i++) {
        if (a[i][0] == a[i-1][0] && a[i][1]==a[i-1][1]) run++;
        else {
            b[sz++] = {a[i-1][0],a[i-1][1],run};
            run = 1;
        }
    }
    b[sz++] = {a[n-1][0],a[n-1][1],run};
    for (LL i = 0; i < sz; i++) {
        if (b[i][2] > 1 && b[i][0] <= lim && b[i][0]*(LL)b[i][0] == b[i][1]+b[i][1]) ans += b[i][2]*(LL)(b[i][2]-1)/2;
        for (LL j = 1; j <= b[i][0] && j <= lim; j++) {
            LL e = b[i][0]*j-b[i][1];
            if (b[i][0] == j && e >= b[i][1]) continue;
            if (e >= 1 && e <= n) {
                ans += b[i][2] * (LL)fr[j][e];
            }
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) if (a[i][0] <= lim) fr[a[i][0]][a[i][1]] = 0;
}

/*

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
