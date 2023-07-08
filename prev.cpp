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

LL n, k, a[MX];

/*
   1) prefix sums, find a, b where b-a is minimum
*/

void solve() {
    cin >> n >> k;
    LL sum = 0;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    LL lo = 1;
    LL hi = sum;
    LL ans = sum;
    while (lo <= hi) {
        LL mid = lo + (hi - lo)/2;
        LL tmpk = 1;
        LL curr = 0;
        LL cmax = 0;
        //cout << "mid: " << mid << endl;
        bool flag = 0;
        for (LL i = 0; i < n; i++) {
            curr += a[i];
            if (curr > mid) {
                cmax = max(cmax, curr - a[i]);
                tmpk++;
                curr = a[i];
                flag = 1;
            }
            cmax = max(cmax, curr);
            //cout <<"n: "<<a[i]<< " " << "c: " << curr << " tmpk " << tmpk << endl;
        }
        if (tmpk <= k && flag) {
            ans = min(ans, cmax);
            hi = mid-1;
        }  else {
            lo = mid+1;
        }
    }
    cout << ans << endl;
}





