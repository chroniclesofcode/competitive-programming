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
const LL MX = 1e3 + 2;

LL grid[MX][MX];
LL row[MX][MX*4];
LL col[MX][MX*4];

LL queries[MX][3];

void Build(LL a[], LL t[], LL vertex, LL left, LL right) {
    if (left == right) {
        t[vertex] = a[left];
    } else {
        LL mid = (left + right) / 2;
        Build(a, t, vertex*2, left, mid);
        Build(a, t, vertex*2+1, mid+1, right);
        t[vertex] = max(t[vertex*2], t[vertex*2+1]);
    }
}

void Update(LL t[], LL curr, LL left, LL right, LL p, LL newv) {
    if (left == right) {
        t[curr] = newv;
    } else {
        LL mid = (left + right) / 2;
        if (p <= mid) {
            Update(t, curr*2, left, mid, p, newv);
        } else {
            Update(t, curr*2+1, mid+1, right, p, newv);
        }
        t[curr] = max(t[curr*2], t[curr*2+1]);
    }
}

LL Query(LL t[], LL qL, LL qR, LL i, LL cL, LL cR) {
    if (cL == qL && cR == qR)
        return t[i];
    LL mid = (cL + cR) / 2;
    LL ans = 0;
    return max(Query(t, max(qL, mid), qR, i * 2 + 1, mid, cR), Query(t, qL, min(qR, mid), i * 2, cL, mid));
}

// THIS DOES NOT PASS ALL CASES FOR SOME REASON I DO NOT KNOW... WILL FIX LATER
// We have 2 arrays of segment trees and query them.

void solve() {
    LL m, n, p;
    cin >> m >> n >> p;
    for (LL i = 0; i < m; i++) {
        for (LL j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (LL i = 0; i < p; i++) {
        LL a, b, c;
        cin >> a >> b >> c;
        queries[i][0] = a;
        queries[i][1] = b;
        queries[i][2] = c;
    }

    for (LL i = 0; i < m; i++) {
        Build(grid[i], row[i], 1, 0, n-1);
    }
    for (LL i = 0; i < n; i++) {
        LL tmp[MX];
        for (LL j = 0; j < m; j++) {
            tmp[j] = grid[j][i];
        }
        Build(tmp, col[i], 1, 0, m-1);
    }
    LL currmax = 0;
    set<LL> skyscrapers;
    for (LL i = 0; i < m; i++) {
        for (LL j = 0; j < n; j++) {
            LL rowmax = row[i][1];
            LL colmax = col[j][1];
            if (grid[i][j] == rowmax && grid[i][j] == colmax) {
                skyscrapers.insert(grid[i][j]);
                currmax++;
            }
        }
    }
    cout << currmax << endl;
 

    for (LL i = 0; i < p; i++) {
        LL a = queries[i][0];
        a--;
        LL b = queries[i][1];
        b--;
        LL h = queries[i][2];
        Update(row[a], 1, 0, n-1, b, h);
        Update(col[b], 1, 0, m-1, a, h);
        LL tmp = grid[a][b];
        grid[a][b] = h;
        LL oldval = skyscrapers.size();
        skyscrapers.erase(tmp);

        LL rowmax = row[a][1];
        LL colmax = col[b][1];
        if (rowmax == colmax) {
            skyscrapers.insert(rowmax);
            for (LL i = 0; i < m; i++) {
                if (i != a)
                    skyscrapers.erase(grid[i][b]);
            }
            for (LL i = 0; i < n; i++) {
                if (i != b)
                    skyscrapers.erase(grid[a][i]);
            }
        } else {
            for (LL i = 0; i < m; i++) {
                if (colmax == row[i][1]) {
                    //cout << "insert " << colmax;
                    skyscrapers.insert(colmax);
                }
            }
            for (LL i = 0; i < n; i++) {
                if (rowmax == col[i][1]) {
                    //cout << "insert " << rowmax;
                    skyscrapers.insert(rowmax);
                }
            }
        }

        if (skyscrapers.size() > oldval) {
            cout << '+';
        } else if (skyscrapers.size() < oldval) {
            cout << '-';
        } else {
            cout << '=';
        }
    }
    cout << endl;
}

