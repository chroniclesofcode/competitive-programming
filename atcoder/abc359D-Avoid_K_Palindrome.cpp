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
constexpr LL MX = 1001;
constexpr LL MD = 998244353;

LL n, m, k;
unordered_map<string, LL> dp[MX];

bool ispal(string &s) {
    LL n = s.size();
    for (LL i = 0; i < n; i++) {
        if (s[i] != s[n-1-i]) return false;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    string s; cin >> s;
    if (k <= 1) { cout << 0 << '\n'; return; }
    dp[0][""] = 1;
    for (LL i = 1; i <= n; i++) {
        for (auto &e : dp[i-1]) {
            string str = e.first;
            if (str.size() == k) str.erase(str.begin());
            // not a wildcard
            if (s[i-1] != '?') {
                str.push_back(s[i-1]);
                if (str.size() < k || !ispal(str)) {
                    dp[i][str] += e.second;
                    dp[i][str] %= MD;
                }
            } else {
                str.push_back('A');
                if (str.size() < k || !ispal(str)) {
                    dp[i][str] += e.second;
                    dp[i][str] %= MD;
                }
                str[str.size()-1] = 'B';
                if (str.size() < k || !ispal(str)) {
                    dp[i][str] += e.second;
                    dp[i][str] %= MD;
                }
            }
        }
    }
    LL ans = 0;
    for (auto &e : dp[n]) {
        ans += e.second;
        ans %= MD;
    }
    cout << ans << '\n';
}

/*
   dp[i][mask] = if the last elements at i is (mask)->A or B
   how many good strings do we have in total? The mask is to
   confirm that we do have a palindrome.

   for all ??? case -> we
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
