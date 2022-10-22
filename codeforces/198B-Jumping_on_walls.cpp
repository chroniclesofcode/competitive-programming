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
#define INF numeric_limits<int>::max()
const LL MX = 2 * 1e5 + 100;
int lwall[MX];
int rwall[MX];

void solve() {
    int n, k;
    cin >> n >> k;
    string l, r;
    cin >> l >> r;

    for (int i = 1; i < MX; i++) {
        lwall[i] = INF;
        rwall[i] = INF;
    }

    int water = 0;
    queue<int> ql, qr;
    if (l[0] != 'X') ql.push(0);
    //if (r[0] != 'X') qr.push(0);
    
    // ql and qr will store our bfs
    // lwall and rwall arrays will store the min
    // moves to reach that specific position
    bool left = true;
    int i;
    while (!ql.empty() || !qr.empty()) {
        //cout << (left ? "left" : "right") << " ";
        if (!ql.empty()) {
            i = ql.front();
            ql.pop();
            //cout <<  i << " lwall: " << lwall[i] << " " << l[i] << '\n';
            if (i+k >= n || i+1 >= n) {
                cout << "YES\n";
                return;
            }
            if (i < lwall[i]) continue;
            if (l[i+1] != 'X' && lwall[i+1] == INF) {
                ql.push(i+1);
                lwall[i+1] = lwall[i] + 1;
            }
            // could be bug case, careful
            //cout << "B... " << i -1 << " " << lwall[i] << "\n";
            if (i > 0 && l[i-1] != 'X' && i - 1 >= lwall[i] + 1 && lwall[i-1] == INF) {
                ql.push(i-1);
                lwall[i-1] = lwall[i] + 1;
            }
            if (i+k < n && r[i+k] != 'X' && rwall[i+k] == INF) {
                qr.push(i+k);
                rwall[i+k] = lwall[i] + 1;
            }
        } else if (!qr.empty()) {
            i = qr.front();
            qr.pop();
            //cout <<  i << " rwall: " << rwall[i] << " " << l[i] << '\n';
            if (i+k >= n || i+1 >= n) {
                cout << "YES\n";
                return;
            }
            if (i < rwall[i]) continue;
            if (r[i+1] != 'X' && rwall[i+1] == INF) {
                qr.push(i+1);
                rwall[i+1] = rwall[i] + 1;
            }
            // could be bug case, careful
            //cout << "B... " << i -1 << " " << rwall[i] << "\n";
            if (i > 0 && r[i-1] != 'X' && i - 1 >= rwall[i] + 1 && rwall[i-1] == INF) {
                qr.push(i-1);
                rwall[i-1] = rwall[i] + 1;
            }
            if (i+k < n && l[i+k] != 'X' && lwall[i+k] == INF) {
                ql.push(i+k);
                lwall[i+k] = rwall[i] + 1;
            }
        }
        /*
        swap(l, r);
        swap(lwall, rwall);
        swap(ql, qr);
        //left = !left;
        */
        
    }
    cout << "NO\n";
}


