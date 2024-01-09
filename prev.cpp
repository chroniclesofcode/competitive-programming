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

int n, m, k, v;
int cost[10];

void solve() {
    cin >> v;
    int small = INF;
    int sd = 0;
    for (int i = 1; i <= 9; i++) {
        cin >> cost[i];
        if (cost[i] < small) {
            small = cost[i];
            sd = i;
        }
    }
    if (small > v) {
        cout << -1 << '\n';
        return;
    }
    int numdig = v/small;
    v -= small*numdig;
    vector<int> ans(numdig, sd);
    for (int i = 0; i < numdig; i++) {
        for (int j = 9; j >= 1; j--) {
            if (v + small - cost[j] >= 0) {
                ans[i] = j;
                v = v + small - cost[j];
                break;
            }
        }
    }
    for (int i = 0; i < numdig; i++) {
        cout << ans[i];
    }
    cout << '\n';
}

/*
   we want as many digits as possible -> use the smallest cost
   to form the maximum amount of digits. Now, the number must
   have that many digits. Then, just test all the cases.
*/



