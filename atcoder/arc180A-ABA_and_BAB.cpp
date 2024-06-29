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

        solve();
}

constexpr LL INF = (LL)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;
LL dp[MX]; 

void solve() {
    cin >> n;
    string s; cin >> s;

    LL ans = 1;
    LL run = 1;
    vector<LL> ret;
    for (LL i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            run++;
            if (i == n-1) ret.push_back(run);
        } else {
            ret.push_back(run);
            run = 1;
        }
    }
    for (auto r : ret) {
        if (r <= 2) continue;
        else if (r <= 4) ans *= 2;
        else {
            LL add = r%2 == 0 ? r/2 : (r+1)/2;
            ans *= add;
        }
        ans %= MD;
    }
    cout << ans << '\n';
}

/*
   ABAB -> 2
   ABA -> 2

   BABABA
   BABABA, BABA, BA

   ABABA
   ABABA, ABA, A
   ABABAB
   ABABAB, ABAB, AB

   B BABABA ABABA AA ABA
   1 * 3 * 3 * 1 * 2
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

