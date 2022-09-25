#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();


MAINRET(t) main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

// Bug I had:
// I always took the least activity time, instead of the
// highest last activity time which is before the start
// time of the current element...
// I used a priority queue before and now Im using a multiset.
// O(nlogn)

void solve() {  
    LL n, k;
    cin >> n >> k;
    pair<LL, LL> a[n];
    for (LL i = 0; i < n; i++) {
        LL s, f;
        cin >> s >> f;
        // Note, finish is the first value
        a[i] = { f, s };
    }
    if (k == 0 || n == 0) {
        cout << 0 << endl;
        return;
    }
    // Sort by finish times
    sort(a, a+n);
    multiset<LL> pq;
    LL ret = 1;
    pq.insert(a[0].first);
    for (LL i = 1; i < n; i++) {
        auto it = pq.lower_bound(a[i].second);
        if (it != pq.begin()) {
            it--;
        }
        LL finish = *it;
        if (finish < a[i].second) {
            pq.erase(it);
            pq.insert(a[i].first);
            ret++;
        } else if (pq.size() < k) {
            pq.insert(a[i].first);
            ret++;
        }
    }
    cout << ret << endl;

}






