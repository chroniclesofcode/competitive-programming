#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long
#define DB int
void solve();


MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    LL t;
    cin >> t;
    while (t--) {
        solve();
    }
}
// Add x[i] + t[i] and x[i] - t[i] to the line. Basically
// you're saying these are the furthest distances away from the
// end goal that they can possibly be. Even if the + is closer,
// the - will be further, and this will account for the time
// they have to wait. Then just average the endpoints.

void solve() {  
    int n;
    cin >> n;
    DB x[n];
    DB t[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<DB> a;
    for (int i = 0; i < n; i++) {
        a.push_back(x[i]+t[i]);
        a.push_back(x[i]-t[i]);
    }

    DB minx = a[0];
    DB maxx = a[0];
    for (int i = 1; i < a.size(); i++) {
        minx = min(minx, a[i]);
        maxx = max(maxx, a[i]);
    }

    DB target = (minx + maxx) / 2;
    cout << target;
    if ((minx + maxx) % 2 != 0) {
        cout << ".5";
    }
    cout << '\n';

}






