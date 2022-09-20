#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {  
    int n, x, y;
    cin >> n >> x >> y;
    if (x != 0 && y != 0) {
        cout << -1 << '\n';
        return;
    } else if (x == 0 && y == 0) {
        cout << -1 << '\n';
        return;
    }  
    int num = x == 0 ? y : x;
    if ((n-1) % num != 0) {
        cout << -1 << '\n';
        return;
    }
    int ct = 0;
    int curr = 1;
    for (int i = 2; i <= n; i++) {
        if (ct == num) {
            curr = i;
            ct = 0;
        }
        cout << curr << " ";
        ct++;
    }
    cout << '\n';

}

/*

   1,2,3,4,5
   either won 2 or won 0
   1 -> 2,3
   4 -> 1,5

   one of them needs to be 0, as there
   always needs to be someone who just loses
   on someone else's winning streak

   1 2 3 4 5 6
   5 games modulo 3 != 0, therefore impossible

   then greedy
*/
