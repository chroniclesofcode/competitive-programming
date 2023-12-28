#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

void solve() {
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            board[i][j] = c;
        }
    }
    auto res = board;
    for (int i = 0; i < n; i++) {
        int ct = 0;
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'U') {
                res[i][j] = ct % 2 == 0 ? 'W' : 'B';
                res[i+1][j] = ct % 2 == 0 ? 'B' : 'W';
                board[i][j] = '.';
                board[i+1][j] = '.';
                ct++;
            }
        }
        if (ct % 2 == 1) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int j = 0; j < m; j++) {
        int ct = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][j] == 'L') {
                res[i][j] = ct % 2 == 0 ? 'W' : 'B';
                res[i][j+1] = ct % 2 == 0 ? 'B' : 'W';
                board[i][j] = '.';
                board[i][j+1] = '.';
                ct++;
            }
        }
        if (ct % 2 == 1) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }
}

