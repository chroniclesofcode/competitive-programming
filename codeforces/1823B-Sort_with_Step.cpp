#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
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

int n, m, k;

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int error = 0;
    vector<int> mark(n+1, 0);
    for (int i = 0; i < k; i++) {
        mark.clear();
        for (int j = i; j < n; j += k) {
            cout << "it: " << i << " mark: " << a[j]-1 << '\n';
            mark[a[j]-1] = 1;
        }
        int err = 0;
        for (int j = i; j < n; j += k) {
            if (!mark[j]) {
                err++;
                error++;
            }
        }
        if (err >= 2) {
            cout << "-1\n"; return;
        }
    }
    cout << "error: " << error << '\n';
    if (error == 0) {
        cout << "0\n";
    } else if (error > 2) {
        cout << "-1\n";
    } else {
        cout << "1\n";
    }
}

/*

*/







