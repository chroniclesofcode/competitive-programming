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


const LL MX = 2 * 1e5 + 100;
LL a[MX];

// two pointer solution: just increment p2 when value is good
// increment p1 when it is not, you will add all possible
// subarrays to get up to ur answer.

// That being said, there's a pretty smart DP solution as well
// dp[i] = min(dp[i-1] + 1, a[i]);
// where dp is the longest good subarray ending on i
// because if a[i] > length of longest, it will be added to it +1
// If it isn't, the last couple of elements will still be good
// NO MATTER WHAT. So if a[i] was 3, it would be like 97, 98, 3
// and it would still be good. :D
// The answer is now sum of all the values at each element
// cuz the amount is the length
// e.g. 97 98 3, 98 3, 3 <- which equals length!

void solve() {
    LL n;
    cin >> n;
    for (LL i = 0; i < n; i++) cin >> a[i];
    LL p1 = 0, p2 = 0;
    LL ret = 0;
    while (p1 < n && p2 < n) {
        LL len = p2 - p1 + 1;
        if (a[p2] >= len) {
            ret += len;
            p2++;
        } else {
            p1++;
        }
    }   
    cout << ret << '\n';
}

