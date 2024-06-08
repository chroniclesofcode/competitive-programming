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
char ans[8][740][740];

void solve() {
    cin >> n;
    ans[0][0][0] = '#';
    int pw = 1;
    for (int l = 1; l <= n; l++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < pw; k++) {
                    for (int m = 0; m < pw; m++) {
                        if (i == 1 && j == 1) {
                            ans[l][i*pw+k][j*pw+m] = '.';
                        } else {
                            ans[l][i*pw+k][j*pw+m] = ans[l-1][k][m];
                        }
                    }
                }
            }
        }
        pw *= 3;
    }
    int lvl = 1;
    for (int i = 0; i < n; i++) lvl *= 3;
    for (int i = 0; i < lvl; i++) {
        for (int j = 0; j < lvl; j++) {
            cout << ans[n][i][j];
        }
        cout << '\n';
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

