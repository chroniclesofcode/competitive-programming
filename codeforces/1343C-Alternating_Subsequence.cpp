#include <bits/stdc++.h>

using namespace std;

void solve();

#define LL long long

int main(void) {
    LL t;
    cin >> t;
    while (t--) {
        solve();
    }
}

// It is just greedy, go through all the alternating pairs
// and add the max of the positives and the max of the negatives
// that are in a row. O(n)

void solve() {
    LL n;
    cin >> n;
    LL a[n];
    for (LL i = 0; i < n; i++) cin >> a[i];
    LL minmax = a[0];
    bool pos = a[0] > 0 ? true : false;
    LL ans = 0;
    for (LL i = 0; i < n; i++) {
        
        if (pos && a[i] > 0) {
            minmax = max(minmax, a[i]);
        } else if (pos && a[i] < 0) {
            ans += minmax;
            pos = false;
            minmax = a[i];
        } else if (!pos && a[i] < 0) {
            minmax = max(minmax, a[i]);
        } else if (!pos && a[i] > 0) {
            ans += minmax;
            pos = true;
            minmax = a[i];
        }
        //cout << "pos: "<<pos<<" ans: "<<ans<<" a[i]: "<<a[i]<<" minmax: "<<minmax<<" last: "<<last<<endl;
    }
    ans += minmax;
    cout << ans << endl;
}


