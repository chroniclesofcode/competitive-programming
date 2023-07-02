#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>


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
ordered_set s;
int n, k;
/*

*/

void solve() {
    cin >> n >> k;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int sz = s.size();
        idx += k;
        idx %= sz;
        auto it = s.find_by_order(idx);
        cout << *it << ' ';
        s.erase(it);
    }
    cout << endl;
    
}





