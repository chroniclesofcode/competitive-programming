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
    while (t--) {
        solve();
    }
}

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n+20, 0);
    LL minpeel = 1e7 + 10;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        minpeel = min(minpeel, a[i]);
    }
    LL steps = 0;
    LL maxpeel = minpeel * 2 - 1;
    for (LL i = 0; i < n; i++) {
        if (a[i] > maxpeel) { 
            steps += a[i] / maxpeel;
            if (a[i] % maxpeel == 0) {
                steps -= 1;
            }
        }
    }
    cout << steps << '\n';
}

/*
   21, maxpeel is 7 -> 1 cut
   */


