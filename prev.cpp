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

int n, m, k;

vector<int> ppl, apa;
/*

*/

void solve() {
    cin >> n >> m >> k;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ppl.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        apa.push_back(x);
    }
    sort(ppl.begin(), ppl.end());
    sort(apa.begin(), apa.end());

    int i = 0, j = 0, ans = 0;
    while (i < ppl.size() && j < apa.size()) {
        int tol = ppl[i];
        int sz = apa[j];
        if (tol+k >= sz && tol-k <= sz) {
            ans++; i++; j++;
        } else if (tol+k < sz) {
            i++;
        } else if (tol-k > sz) {
            j++;
        }
    }
    cout << ans << endl;
}





