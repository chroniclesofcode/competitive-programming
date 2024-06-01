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
constexpr int MD = (int)1e9 + 7;

int n, m, k;

class Fenwick2D {
public:
    int n, m;
    vector<vector<int>> BIT;

    Fenwick2D(int sn, int sm) : n{sn}, m{sm}, BIT(sn+1, vector<int>(sm+1)) {}

    void add(int x, int y, int add) {
        x++; y++;
        for (int i = x; i <= n; i += i&-i) {
            for (int j = y; j <= m; j += j&-j) {
                BIT[i][j] += add;
            }
        }
    }

    int query(int x, int y) {
        x++; y++;
        int sum = 0;
        for (int i = x; i > 0; i -= i&-i) {
            for (int j = y; j > 0; j -= j&-j) {
                sum += BIT[i][j];
            }
        }
        return sum;
    }
};

void solve() {
    int q;
    cin >> n >> q;
    vector<vector<int>> g(n, vector<int>(n));
    Fenwick2D f(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char tree; cin >> tree;
            if (tree == '*') g[i][j] = 1;
            else g[i][j] = 0;
            f.add(i, j, g[i][j]);
        }
    }
    
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y; x--; y--;
            f.add(x, y, !g[x][y] - g[x][y]);
            g[x][y] = !g[x][y];
        } else {
            int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
            y1--; x1--; y2--; x2--;
            int ans = f.query(y2, x2);
            if (x1 > 0) ans -= f.query(y2, x1-1);
            if (y1 > 0) ans -= f.query(y1-1, x2);
            if (x1 > 0 && y1 > 0) ans += f.query(y1-1, x1-1);
            cout << ans << '\n';
        }
    }
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
