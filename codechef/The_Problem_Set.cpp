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
#define INF numeric_limits<LL>::max() / 2
const LL MX = 1e5 + 100;
LL n = MX;
LL sum[4*MX];
//LL lazyadd[4*MX], sum[4*MX];
//LL lazyset[4*MX], fazyset[4*MX];
LL maxrt[4*MX];
LL minrt[4*MX];
bool incr[4*MX], decr[4*MX];

/*
   6 3
   6 5 4 3 2 1
   D 1 6
   U 6 3
   D 1 6

   6 6
   6 5 4 6 2 2
   D 1 2
   I 3 4
   D 1 6
   U 4 3
   I 3 4
   D 1 6

   6 3
   2 2 2 4 5 6
   I 1 6
   U 3 5
   I 1 6

*/

//const LL UNSET = -1;

LL orig[MX];

void recalculate(LL id, long long l, long long r) {
    sum[id] = sum[id*2] + sum[id*2+1];

    maxrt[id] = max(maxrt[id*2], maxrt[id*2+1]);
    minrt[id] = min(minrt[id*2], minrt[id*2+1]);

    incr[id] = incr[id*2] && incr[id*2+1] && maxrt[id*2] <= minrt[id*2+1];
    decr[id] = decr[id*2] && decr[id*2+1] && minrt[id*2] >= maxrt[id*2+1];
}


void update(LL uL, LL uR, LL v, LL i = 1, LL cL = 0, LL cR = n) {
    if (uL == cL && uR == cR) {
        sum[i] = v;
        maxrt[i] = v;
        minrt[i] = v;
        incr[i] = true;
        decr[i] = true;
        return;
    }
    LL mid = (cL + cR) / 2;
    if (uL < mid) update(uL, min(uR, mid), v, i * 2, cL, mid);
    if (uR > mid) update(max(uL, mid), uR, v, i * 2 + 1, mid, cR);
    recalculate(i, cL, cR);
}

long long querySum(LL qL, LL qR, LL i = 1, LL cL = 0, LL cR = n) {
    //cout << "frog " << qL << " " << qR << " " << sum[i] << endl;
    if (qL == cL && qR == cR) {
        return sum[i];
    }
    LL mid = (cL + cR) / 2;
    long long ans = 0;
    if (qL < mid) ans += querySum(qL, min(qR, mid), i * 2, cL, mid);
    if (qR > mid) ans += querySum(max(qL, mid), qR, i * 2 + 1, mid, cR);
    return ans;
}

long long queryMax(LL qL, LL qR, LL i = 1, LL cL = 0, LL cR = n) {
    if (qL == cL && qR == cR) {
        return maxrt[i];
    }
    LL mid = (cL + cR) / 2;
    long long ans1 = 0, ans2 = 0;
    if (qL < mid) ans1 = queryMax(qL, min(qR, mid), i * 2, cL, mid);
    if (qR > mid) ans2 = queryMax(max(qL, mid), qR, i * 2 + 1, mid, cR);
    return max(ans1, ans2);
}

long long queryMin(LL qL, LL qR, LL i = 1, LL cL = 0, LL cR = n) {
    if (qL == cL && qR == cR) {
        return minrt[i];
    }
    LL mid = (cL + cR) / 2;
    long long ans1 = INF, ans2 = INF;
    if (qL < mid) ans1 = queryMin(qL, min(qR, mid), i * 2, cL, mid);
    if (qR > mid) ans2 = queryMin(max(qL, mid), qR, i * 2 + 1, mid, cR);
    return min(ans1, ans2);
}

bool queryIncr(LL qL, LL qR, LL i = 1, LL cL = 0, LL cR = n) {
    //cout << "run " << qL << " " << qR << endl;
    if (qL == cL && qR == cR) {
        return incr[i];
    }
    
    LL mid = (cL + cR) / 2;
    LL mini = INF, maxi = -INF;
    bool r1 = true, r2 = true;
    if (qL < mid) {
        r1 = queryIncr(qL, min(qR, mid), i * 2, cL, mid);
        maxi = max(maxi, queryMax(qL, min(qR, mid)));
    }
    if (qR > mid) {
        r2 = queryIncr(max(qL, mid), qR, i * 2 + 1, mid, cR);
        mini = min(mini, queryMin(max(qL, mid), qR));
    }
    //cout << "BRUH " << mid << " "<< qL << " " << qR << " " << maxi << " " << mini << endl;

    return r1 && r2 && maxi <= mini;
}



bool queryDecr(LL qL, LL qR, LL i = 1, LL cL = 0, LL cR = n) {
    if (qL == cL && qR == cR) {
        return decr[i];
    }
    LL mid = (cL + cR) / 2;
    LL mini = INF, maxi = -INF;
    bool r1 = true, r2 = true;
    if (qL < mid) {
        r1 = queryDecr(qL, min(qR, mid), i * 2, cL, mid);
        mini = min(mini, queryMin(qL, min(qR, mid)));
    }
    if (qR > mid) {
        r2 = queryDecr(max(qL, mid), qR, i * 2 + 1, mid, cR);
        maxi = max(maxi, queryMax(max(qL, mid), qR));
    }
//    cout << "BRUH " << mid << " "<< qL << " " << qR << " " << maxi << " " << mini << endl;

    return r1 && r2 && maxi <= mini;
}


void Build2() {
    for (LL i = 0; i < n; i++) {
        update(i, i+1, orig[i]);
    }
}

void debug() {
    for (LL i = 1; i <= 4 * (n-1); i++) {
        cout << sum[i] << " ";
    }
    cout << endl << endl;
    for (LL i = 1; i <= 4 * (n-1); i++) {
        cout << maxrt[i] << " ";
    }
    cout << endl << endl;
    for (LL i = 1; i <= 4 * (n-1); i++) {
        cout << minrt[i] << " ";
    }
    cout << endl << endl;
    for (LL i = 1; i <= 4 * (n-1); i++) {
        cout << incr[i] << " ";
    }
    cout << endl << endl;
    for (LL i = 1; i <= 4 * (n-1); i++) {
        cout << decr[i] << " ";
    }
    cout << endl << endl;

}

void solve() {
    LL N, M;
    cin >> N >> M;
    n = N;
    for (LL i = 0; i < N; i++) {
        cin >> orig[i];
    }
    //Build(1, 0, N-1);
    Build2();
    while (M--) {
        char c;
        LL a, b;
        cin >> c >> a >> b;
        a--;
        if (c == 'U') {
            update(a, a+1, b);
        } else if (c == 'M') {
            cout << queryMax(a, b) << '\n';
        } else if (c == 'S') {
            cout << querySum(a, b)  << '\n';
        } else if (c == 'I') {
            cout << queryIncr(a, b) << '\n';
        } else if (c == 'D') {
            cout << queryDecr(a, b) << '\n';
        }
    }
    //debug();
}


