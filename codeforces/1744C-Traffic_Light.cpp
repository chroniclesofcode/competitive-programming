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
const LL MX = 1e6;
LL a[MX];
LL pref[MX];

void solve() {
    LL n;
    cin >> n;
    char c;
    cin >> c;
    string s;
    cin >> s;
    LL ct = -1, red = 0, green = 0, yellow = 0, early = -1;
    LL tmpr = 0, tmpy = 0;
    for (LL i = n-1; i >= 0; i--) {
        if (ct == -1 && s[i] != 'g') {
            continue;
        } else if (s[i] == 'g') {
            if (ct == -1) early = i;
            ct = 0;
        } else {
            ct++;
            if (s[i] == 'r') {
                red = max(red, ct);
            }
            if (s[i] == 'y') yellow = max(yellow, ct);
        }
    }
    ct++;
    for (LL i = n-1; i > early; i--) {
        if (s[i] == 'r') {
            red = max(red, ct);
        } else if (s[i] == 'y') {
            yellow = max(yellow, ct);
        }
        ct++;
    }
    if (c == 'g') {
        cout << 0;
    } else if (c == 'y') {
        cout << yellow;
    } else if (c == 'r') {
        cout << red;
    }
    cout << '\n';
}

