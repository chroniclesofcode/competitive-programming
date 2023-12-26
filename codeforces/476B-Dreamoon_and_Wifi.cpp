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

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
constexpr int COMB = 12;

double comb[COMB][COMB];

void solve() {
    cout << fixed << setprecision(12);
    for (int i = 0; i < COMB; i++) {
        comb[i][i] = comb[i][0] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }
    string source, target;
    cin >> source; cin >> target;
    n = source.size();
    int pc = 0, mc = 0;
    for (char c : source) {
        if (c == '+') pc++;
        else mc++;
    }
    int pt = 0, mt = 0, qt = 0;
    for (char c : target) {
        if (c == '+') pt++;
        else if (c == '-') mt++;
        else qt++;
    }
    double ans = 0.0;
    if (pc < pt || mc < mt) {
        cout << ans << '\n';
        return;
    }
    ans = 1.0;
    if (qt == 0) {
        cout << ans << '\n';
        return;
    }
    pc = pc - pt; mc = mc - mt;
    int tot = 1 << qt;
    double tmp = comb[qt][pc];
    ans = tmp / (double)tot;
    cout << ans << '\n';
}

/*

*/
