#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

LL counter;
MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    for (counter = 1; counter <= t; counter++) 
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 1001;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
int g[1001][1001], rot[1001][1001];

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a; cin >> a;
            g[i][j] = a;
        }
    }
    if (n == 1 || (n == 0 && k == 0)) {
        cout << "YES\n"; return;
    } else if (n == 0) {
        cout << "NO\n"; return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rot[i][n-1-j] = g[n-1-i][j];
        }
    }
    int diff = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rot[i][j] != g[i][j]) diff++;
        }
    }
    
    diff /= 2;
    if (diff > k) {
        cout << "NO\n"; return;
    }
    if ((k-diff)%2 == 0 || n%2 == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
}

/*

*/







