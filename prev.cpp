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
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;
int a, b;

int calc(int x, int y) {
    int ct = 1;
    while (x > 1) {
        x = (x+1)/2;
        ct++;
    }
    while (y > 1) {
        y = (y+1)/2;
        ct++;
    }
    return ct;
}

void solve() {
    cin >> n >> m >> a >> b;
    if (n == 1 && m == 1) {
        cout << 0 << '\n';
        return;
    }
    
    cout << min(calc(min(n-a+1,a),m), calc(n,min(m-b+1,b))) << '\n';
}

/*

*/