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
#define arr array<LL, 2>
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n, x;

/*

*/

void solve() {
    cin >> n >> x;
    vector<LL> a(n), b(n), ans(n, -1);
    vector<arr> q;
    for (LL i = 0; i < n; i ++) {
        LL tmp; cin >> tmp;
        a[i] = tmp;
        q.push_back({ tmp, i });
    }
    sort(q.begin(), q.end());
    for (LL i = 0; i < n; i++) {
        LL tmp; cin >> tmp;
        b[i] = tmp;
    }
    sort(b.begin(), b.end());
    LL ct = 0;
    LL sz = q.size();
    LL mark = sz-1;
    LL ptr = x-1;
    for (LL i = sz-1; i >= 0; i--) {
        if (ct >= x) {
            break;
        }
        if (ptr < 0 || q[i][0] <= b[ptr]) {
            cout << "NO\n"; return;
        }
        ans[q[i][1]] = b[ptr];
        ptr--;
        ct++;
        mark--;
    }
    ptr = n-1;
    for (LL i = mark; i >= 0; i--) {
        if (q[i][0] > b[ptr] || ptr < 0) {
            cout << "NO\n"; return;
        }
        ans[q[i][1]] = b[ptr--];
    }
    cout << "YES\n";
    for (auto e : ans) {
        cout << e << ' ';
    }
    cout << '\n';
}





