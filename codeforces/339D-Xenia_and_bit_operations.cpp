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

void b(LL a[], LL t[], LL vertex, LL left, LL right, bool isOr) {
    if (left == right) {
        t[vertex] = a[left];
    } else {
        LL mid = (left + right) / 2;
        b(a, t, vertex*2, left, mid, !isOr);
        b(a, t, vertex*2+1, mid+1, right, !isOr);
        if (isOr) {
            t[vertex] = t[vertex*2] | t[vertex*2+1];
        } else {
            t[vertex] = t[vertex*2] ^ t[vertex*2+1];
        }
    }
}

void update(LL a[], LL t[], LL curr, LL left, LL right, LL p, LL newv, bool isOr) {
    if (left == right) {
        t[curr] = newv;
    } else {
        LL mid = (left + right) / 2;
        if (p <= mid) {
            update(a, t, curr*2, left, mid, p, newv, !isOr);
        } else {
            update(a, t, curr*2+1, mid+1, right, p, newv, !isOr);
        }
        if (isOr) {
            t[curr] = t[curr*2] | t[curr*2+1];
        } else {
            t[curr] = t[curr*2] ^ t[curr*2+1];
        }
    }
}

// Segment tree
// root is the final answer
// each leaf is each value, every layer switch
// between OR and XOR
// every time I change a value, I traverse
// from the root to value itself and change it
void solve() {  
    LL n, m;
    cin >> n >> m;
    LL numn = 1 << n;
    LL a[numn+10];
    for (LL i = 0; i < numn; i++) {
        cin >> a[i];
    }
    
    // Segment tree
    LL t[4*numn+10];
    bool topOr = n % 2 == 1;
    b(a, t, 1, 0, numn-1, topOr);

    /*
    for (LL i = 0; i < 4*n+10; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
    */
    LL p, newv;
    for (LL i = 0; i < m; i++) {
        cin >> p >> newv;
        update(a, t, 1, 0, numn-1, p-1, newv, topOr);
        cout << t[1] << '\n';
    }
}






