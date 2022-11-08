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
LL a[MX];
LL z1, z2;
LL n = MX;

LL lazyadd[4*MX], sum0[4*MX], sum1[4*MX], sum2[4*MX];

void recalculate(LL id, long long l, long long r) {
    bool leaf = r - l == 1;
    if (!leaf) {
        sum0[id] = sum0[id*2] + sum0[id*2 + 1];
        sum1[id] = sum1[id*2] + sum1[id*2 + 1];
        sum2[id] = sum2[id*2] + sum2[id*2 + 1];
    }

    if (lazyadd[id] == 1) {
        LL tmp0 = sum0[id];
        LL tmp1 = sum1[id];
        LL tmp2 = sum2[id];
        sum0[id] = tmp2;
        sum1[id] = tmp0;
        sum2[id] = tmp1;
    } else if (lazyadd[id] == 2) {
        LL tmp0 = sum0[id];
        LL tmp1 = sum1[id];
        LL tmp2 = sum2[id];
        sum0[id] = tmp1;
        sum1[id] = tmp2;
        sum2[id] = tmp0;
    }
     

     if (leaf) {
         lazyadd[id] = 0;
     }
        
    /*
    sum[id] = lazyadd[id] * (r - l);
    if (r - l != 1) {
        sum[id] += sum[id * 2];
        sum[id] += sum[id * 2 + 1];
    }
    */
}

void update_lazy(LL id, long long v, long long l, long long r) {

    lazyadd[id] += v;
    lazyadd[id] %= 3;

    recalculate(id, l, r);
}

void propagate(LL id, long long l, long long r) {
    long long mid = (l + r) / 2;
    update_lazy(id * 2, lazyadd[id], l, mid);
    update_lazy(id * 2 + 1, lazyadd[id], mid, r);
    lazyadd[id] = 0;
}

void update(LL uL, LL uR, LL v, LL i = 1, LL cL = 0, LL cR = n) {
    if (uL == cL && uR == cR) {
        update_lazy(i, v, cL, cR);
        return;
    }
    propagate(i, cL, cR);
    LL mid = (cL + cR) / 2;
    if (uL < mid) update(uL, min(uR, mid), v, i * 2, cL, mid);
    if (uR > mid) update(max(uL, mid), uR, v, i * 2 + 1, mid, cR);
    recalculate(i, cL, cR);
}

long long query(LL qL, LL qR, LL i = 1, LL cL = 0, LL cR = n) {
    if (qL == cL && qR == cR) {
        return sum0[i];
    }
    propagate(i, cL, cR);
    LL mid = (cL + cR) / 2;
    long long ans = 0;
    if (qL < mid) ans += query(qL, min(qR, mid), i * 2, cL, mid);
    if (qR > mid) ans += query(max(qL, mid), qR, i * 2 + 1, mid, cR);
    return ans;
}

void Build(LL vertex, LL left, LL right) {
    if (left == right) {
        sum0[vertex] = 1;
    } else {
        LL mid = (left + right) / 2;
        Build(vertex*2+1, left, mid);
        Build(vertex*2, mid+1, right);
        sum0[vertex] = sum0[vertex*2] + sum0[vertex*2+1];
    }
}

void debug() {
    for (LL i = 0; i <= 3*n; i++) {
        cout << lazyadd[i] << " ";
    }
    cout << endl << endl;


    for (LL i = 0; i <= 3*n; i++) {
        cout << sum0[i] << " ";
    }
    cout << endl;

    for (LL i = 0; i <= 3*n; i++) {
        cout << sum1[i] << " ";
    }
    cout << endl;

    for (LL i = 0; i <= 3*n; i++) {
        cout << sum2[i] << " ";
    }
    cout << endl;


}
void solve() {
    cin >> z1 >> z2;
    n = z1;
    Build(1, 0, n-1);
   
    while (z2--) {
        LL c, a, b;
        cin >> c >> a >> b;
        //cout << "TEST " << endl;
        if (c == 0) {
            update(a, b+1, 1);
        } else {
            cout << query(a, b+1) << '\n';
        }
        //debug();
        //cout << endl;
    }
}


