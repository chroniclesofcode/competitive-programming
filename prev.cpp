#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
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
const LL MX = (int)1e5+1;
//const LL MOD = 1e7;

int n;
LL pref[MX];
/*

*/

void solve() {
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b.push_back(x);
        a.push_back(x);
    }
    unordered_map<int, int> m;
    sort(a.begin(), a.end());
    LL p = a[0];
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (p < a[i]) {
            while (j < i) {
                m[a[j]] = i-1;
                j++;
            }
        }
        p += a[i];
    }
    while (j < n) {
        m[a[j]] = n-1;
        j++;
    }
    for (int i = 0; i < n; i++) {
        cout << m[b[i]] << ' ';
    }
    cout << '\n';
}





