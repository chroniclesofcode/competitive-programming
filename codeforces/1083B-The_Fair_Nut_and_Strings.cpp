#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

void solve() {
    LL n, k;
    cin >> n >> k;
    string s, t;
    cin >> s;
    cin >> t;
    
    if (s == t) {
        cout << n << endl;
        return;
    } else if (k == 0) {
        cout << 0 << endl;
        return;
    } else if (k == 1) {
        cout << n << endl;
        return;
    }

    LL c = 0;

    // s poLLer, t poLLer
    LL sp = 0;
    LL tp = 0;

    // Find the first spot where they
    // differ, c increments as well as
    // they are all prefixes as well
    while (s[sp] == t[tp]) {
        sp++; tp++;
        c++;
    }
    //c += 2;

    LL strings_left = k - 2;

    // Note: total_nodes is equal to number of
    // prefixes
    LL paths = 1;
    for (LL i = sp; i < n; i++) {
        paths *= 2;
        if (s[i] == 'b') {
            paths -= 1;
        } 
        if (t[i] == 'a') {
            paths -= 1;
        }

        paths = min(paths, k);

        c += min(paths, k);
    }

    cout << c << endl;

}
