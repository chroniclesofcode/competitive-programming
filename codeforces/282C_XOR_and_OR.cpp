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


void solve() {
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "NO\n";
        return;
    } else if (a == b) {
        cout << "YES\n";
        return;
    }
    int aones = 0, bones = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') aones++;
        if (b[i] == '1') bones++;
    }
    if (aones > 0 && bones == 0) {
        cout << "NO\n"; return;
    } else if (bones > 0 && aones == 0) {
        cout << "NO\n"; return;
    } else if (bones > 0 && aones > 0) {
        cout << "YES\n"; return;
    } else {
        cout << "YES\n"; return;
    }
}

/*
    11 = 01,10
    00 = 00
    10 = 11
*/



