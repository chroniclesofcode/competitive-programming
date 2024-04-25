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
    LL t; cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;


void solve() {
    cin >> n >> m;
    int top = n * m;
    if (m % 2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << i*m + j+1 << ' ';
            }
            cout << '\n';
        }
        return;
    } else if (n % 2 == 0) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                cout << i*n + j + 1 << ' ';
            }
            cout << '\n';
        }
        return;
    }
    int ct = 1;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m ; j++) {
            cout << i*m + j+1 << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i < n; i += 2) {
        for (int j = 0; j < m ; j++) {
            cout << i*m + j+1 << ' ';
        }
        cout << '\n';
    }
}

/*
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

1
11
21
6
1
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
