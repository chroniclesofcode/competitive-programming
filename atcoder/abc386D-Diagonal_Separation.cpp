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

int n, m, k, q;


void solve() {
    cin >> n >> m;
    vector<arr2> black, white;
    for (int i = 0; i < m; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'B') {
            black.push_back({x, y});
        } else if (c == 'W') {
            white.push_back({x, y});
        }
    }
    sort(black.begin(), black.end());
    sort(white.begin(), white.end());
    int j = 0;
    int smally = INT_MAX;
    for (int i = 0; i < black.size(); i++) {
        while (j < white.size() && white[j][0] <= black[i][0]) {
            smally = min(smally, white[j][1]);
            j++;
        }
        if (smally <= black[i][1]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

/*

*/