#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

int n, x, a[MX];
unordered_map<int,int> m;
unordered_map<int, array<int,2>> tsum;
/*
*/

void solve() {
    cin >> n >> x;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]] = i+1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            tsum[a[i]+a[j]] = { i+1, j+1 };
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int val = a[i]+a[j];
            auto res = tsum[x-val];
            if (res[0] > 0) {
                if (i+1 != res[0] && j+1 != res[0] && i+1 != res[1] && j+1 != res[1]) {
                    cout << i+1 << ' ' << j+1 << ' ' << res[0] << ' ' << res[1] << endl;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";

}





