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

#define arr array<int,2>
struct CmpPrice {
    bool operator()(arr& a, arr& b) {
        return a[0] > b[0];
    }
};
std::map<int, std::list<arr>, CmpPrice> m;
int n;

/*

*/

void solve() {
    m[4] = {1, 2};
    m[2] = {5, 2};
    m[9] = {2, 3};
    m[1] = {1, 4};
    m[2] = {9, 5};
    m[8] = {3, 3};
    
}





