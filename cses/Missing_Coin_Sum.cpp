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

LL n;
vector<LL> a;
/*
    Very difficult solution I must admit. We iterate through the sorted array and check
    for each i if the current value is greater than the sum(0..i-1). The intuition is a 
    bit tricky, but let's first take a look at the main idea: basically, if the current
    value is LESS than the sum, we are actually able to REWIND the sum back to any value
    less than the current value, and then make sum+1. E.g. if sum is currently 10, and the
    current value is like 8 -> it's sort of like DP, we know for sure since the sum is 10, that
    means every number before it is able to be made. So we can just make 3, then add 8 to make
    11. However, if the current value is MORE than the sum, we cannot rewind 10 back to -1 to
    accomodate for say, 11. So that's pretty much the whole idea, the algo is straightforward
    from there.
*/

void solve() {
    cin >> n;
    LL x;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    if (a[0] != 1) {
        cout << 1 << endl;
        return;
    }
    LL res = 1;
    LL crs = a[0];
    for (LL i = 1; i < n; i++) {
        if (a[i] > crs+1) {
            res = crs+1;
            break;
        }
        crs += a[i];
        res = crs+1;
    }
    cout << res << endl;

}





