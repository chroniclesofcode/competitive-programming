#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    //std::cin.tie(nullptr);
    //std::cin.sync_with_stdio(false);
        solve();
}
#define INF numeric_limits<LL>::max() / 2
const LL MX = 1e5+100;

/*
   6 7 1 6 5 4 3 2
   Q 1 1
   Q 2 2
   Q 6 6
   U 1 3 4
   Q 1 1
   Q 2 2
   Q 6 6

   6 7
   6 8 1 2 0 7
   Q 1 6
   Q 3 5
   U 2 3 4
   Q 1 6
   Q 3 5
   U 1 6 3
   Q 4 5

   */

int N, n, m;
long long lazyadd[4*MX], maxrt[4*MX];

void recalculate(int id, long long l, long long r) {
    maxrt[id] = max(maxrt[id], lazyadd[id]);
    if (r - l != 1) {
        maxrt[id] = max({maxrt[2*id], maxrt[id*2+1], maxrt[id]});
    }
}
void update_lazy(int id, long long v, long long l, long long r) {
    lazyadd[id] = max(lazyadd[id], v);
    recalculate(id, l, r);
}
void propagate(int id, long long l, long long r) {
    long long mid = (l + r) / 2;
    update_lazy(id * 2, lazyadd[id], l, mid);
    update_lazy(id * 2 + 1, lazyadd[id], mid, r);
    lazyadd[id] = 0;
}

void update(int uL, int uR, int v, int i = 1, int cL = 0, int cR = n) {
    if (uL == cL && uR == cR) {
        update_lazy(i, v, cL, cR);
    return;
}
    propagate(i, cL, cR);
    int mid = (cL + cR) / 2;
    if (uL < mid) update(uL, min(uR, mid), v, i * 2, cL, mid);
    if (uR > mid) update(max(uL, mid), uR, v, i * 2 + 1, mid, cR);
    recalculate(i, cL, cR);
}
long long query(int qL, int qR, int i = 1, int cL = 0, int cR = n) {
    if (qL == cL && qR == cR) {
    return maxrt[i];
}
    propagate(i, cL, cR);
    int mid = (cL + cR) / 2;
    long long ans1 = 0, ans2 = 0;
    if (qL < mid) ans1 = query(qL, min(qR, mid), i * 2, cL, mid);
    if (qR > mid) ans2 = query(max(qL, mid), qR, i * 2 + 1, mid, cR);
    return max(ans1, ans2);
}

void solve() {
    cin >> n >> m;
    N = n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        update(i, i+1, a);
    }

    for (int i = 0; i < m; i++) {
        char M;
        int l1, r, x;
        cin >> M >> l1 >> r;
        l1--;
        if (M == 'U') {
            cin >> x;
            update(l1, r, x);
        } else if (M == 'Q') {
            cout << query(l1, r) << '\n';
        }
    }
}





