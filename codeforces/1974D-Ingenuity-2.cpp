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
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;

void solve() {
    cin >> n;
    string s; cin >> s;
    int nth = 0, sth = 0, est = 0, wst = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') nth++;
        else if (s[i] == 'S') sth++;
        else if (s[i] == 'E') est++;
        else if (s[i] == 'W') wst++;
    }
    int canceln = min(nth, sth);
    int cancele = min(est, wst);
    int tn = nth-canceln, ts = sth-canceln, te = est-cancele, tw = wst-cancele;
    if (tn%2 || te%2 || ts%2 || tw%2 || s.size() < 2 || (s.size()==2 && s[0]!=s[1])) {
        cout << "NO\n";
        return;
    }
    int ct1 = 0, ct2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') {
            if (nth) { cout << (nth%2 ? 'R' : 'H'); nth--; }
        } else if (s[i] == 'S') {
            if (sth) { cout << (sth%2 ? 'R' : 'H'); sth--; }
        } else if (s[i] == 'E') {
            if (est) { cout << (est%2 ? 'H' : 'R'); est--; }
        } else if (s[i] == 'W') {
            if (wst) { cout << (wst%2 ? 'H' : 'R'); wst--; }
        }
    }
    cout << '\n';
}

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
