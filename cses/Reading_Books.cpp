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
   we just read books, one starts from longest, one 
   starts from shortest.
   when the shortest meets the longest, the shortest can
   go to the back of the longest and start reading the
   longest book. From then on, the longest can finish his
   book (guaranteed before shortest reaches them), and then
   finish off the shortest's books = sum of all times.

   The only situation where this cannot happen is when shortest
   meets longest and longest is still on his first book - which
   is then first book * 2.
*/

void solve() {
    cin >> n;
    LL x;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    LL j = n-1;
    LL sum = 0;
    LL rev = a[j];
    for (LL i = 0; i < n; i++) {
        sum += a[i];
    }
    if (a[n-1] > sum - a[n-1]) {
        cout << a[n-1] * 2;
    } else {
        cout << sum;
    }
    cout << endl;
}





