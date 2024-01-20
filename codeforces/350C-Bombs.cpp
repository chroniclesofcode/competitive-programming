#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<LL,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;


void solve() {
    cin >> n;
    vector<array<LL,2>> c;
    for (LL i = 0; i < n; i++) {
        LL a, b;
        cin >> a >> b;
        c.push_back({a,b});
    }
    sort(c.begin(), c.end(), [](array<LL,2> a, array<LL,2> b) {
        return (a[0]*a[0]+a[1]*a[1]) < (b[0]*b[0]+b[1]*b[1]);
    });
    LL ct = 0;
    for (auto e : c) {
        if (e[0] == 0 || e[1] == 0) {
            ct += 4;
        } else {
            ct += 6;
        }
    }
    cout << ct << '\n';
    for (auto e : c) {
        if (e[0] > 0) {
            cout << "1 " << e[0] << " R\n";
        } else if (e[0] < 0) {
            cout << "1 " << -e[0] << " L\n";
        }
        if (e[1] > 0) {
            cout << "1 " << e[1] << " U\n";
        } else if (e[1] < 0) {
            cout << "1 " << -e[1] << " D\n";
        }
        cout << 2 << '\n';
        if (e[0] > 0) {
            cout << "1 " << e[0] << " L\n";
        } else if (e[0] < 0) {
            cout << "1 " << -e[0] << " R\n";
        }
        if (e[1] > 0) {
            cout << "1 " << e[1] << " D\n";
        } else if (e[1] < 0) {
            cout << "1 " << -e[1] << " U\n";
        }
        cout << 3 << '\n';
    }
}

/*

*/



