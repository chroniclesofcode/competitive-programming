#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const int MX = 262144;
int a[MX];

// We just go through the tree starting from pairs, then quadruples
// etc, and swap their very first value if they are not sorted in
// order. This is because you only really have to look at the
// first value to know if it's going to be sorted.
// If the values differ by i or more, then it's impossible.
// e.g. in the first pair of 2, each value obviously has to be adjacent
// to each other like 1, 3 can never be sorted cuz you need to have a
// 2 in the middle. This will apply for every higher group as well.
// if this property doesn't hold, we output -1.

void solve() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) cin >> a[i];

    int ret = 0;
    // i is how much to shift to next group
    for (int i = 2; i <= m; i <<= 1) {
        for (int j = 0; j < m; j += i) {
            if (abs(a[j] - a[i/2+j]) >= i) {
                cout << -1 << '\n';
                return;
            }
            if (a[j] > a[i/2+j]) {
                swap(a[j], a[i/2+j]);
                ret++;
            }
        }
    }
    cout << ret << '\n';
}

