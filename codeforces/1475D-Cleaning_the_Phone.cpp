#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long
void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL n, m, a[MX];
vector<LL> ones(MX), twos(MX);

/*

*/

void solve() {
    ones.clear();
    twos.clear();
    cin >> n >> m;
    LL tot = 0;
    LL value;
    for (LL i = 0; i < n; i++) {
        cin >> value;
        a[i] = value;
        tot += value;
    }

    for (LL i = 0; i < n; i++) {
        cin >> value;
        if (value == 1) {
            ones.push_back(a[i]);
        } else {
            twos.push_back(a[i]);
        }
    }
    if (tot < m) {
        cout << -1 << '\n';
        return;
    }

    sort(ones.begin(), ones.end(), greater<LL>());
    sort(twos.begin(), twos.end(), greater<LL>());

    /*
    cout << "ONES\n";
    for (int i = 0; i < ones.size(); i++) cout << ones[i] << ' ';
    cout << "TWOS\n";
    for (int i = 0; i < twos.size(); i++) cout << twos[i] << ' ';
    cout << endl;
    */

    LL j = 0;
    if (twos.size() == 0) j = -1;
    tot = 0;
    for (; j < twos.size(); j++) {
        tot += twos[j];
        if (tot >= m || j == twos.size() - 1) break;
    }

    LL ans = tot >= m ? (2 * (j+1)) : INF;
    if (tot >= m && j >= 0) {
        tot -= twos[j];
        j--;
    }

    for (LL i = 0; i < ones.size(); i++) {
        tot += ones[i];
        if (tot >= m)
            ans = min(ans, (1+i) + 2*(1+j));
        while (tot >= m && j >= 0) {
            tot -= twos[j];
            j--;
            if (tot >= m)
                ans = min(ans, (1+i) + 2*(1+j));
        }

    }
    cout << ans << '\n';

}





