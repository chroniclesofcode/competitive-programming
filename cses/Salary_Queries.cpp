#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define arr pair<int,int>
#define ordered_set tree<arr,null_type,less<arr>,rb_tree_tag,tree_order_statistics_node_update>


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
int n, q;
int p[MX];
/*

*/

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[i] = x;
        s.insert({x, i});
    }
    for (int i = 0; i < q; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == '!') {
            a--;
            s.erase({ p[a], a });
            p[a] = b;
            s.insert({ b, a });
        } else {
            int LIM = INT_MAX;
            cout << s.order_of_key({b, LIM}) - s.order_of_key({a-1, LIM}) << '\n';
        }
    }

}





