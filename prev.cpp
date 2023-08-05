#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

int n, type[MX];


/*
   max number is 3. If even number, we can just go 1212121

   if there is at least one pair next to each other, you can
   go 1221212121, so just connect that pair and the rest'll be
   even

   else it's just 3.

*/

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> type[i];
    }
    
    int ct = 1;
    int wow = 0;
    for (int i = 1; i < n; i++) {
        if (type[i] != type[i-1]) {
            ct++;
        }
        if (type[i] == type[i-1]) {
            wow = 1;
        }
    }
    int lasto = 0;
    if (wow == 0 && type[0] == type[n-1]) {
        wow = 1;
        lasto = 1;
    }

    if (ct == 1) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            cout << 1 << ' ';
        }
    } else if (n % 2 == 0) {
        cout << 2 << '\n';
        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr = (curr%2)+1;
            cout << curr << ' ';
        }
    } else if (ct % 2 == 0) {
        cout << 2 << '\n';
        int curr = 1;
        cout << 1 << ' ';
        for (int i = 1; i < n; i++) {
            if (type[i] == type[i-1]) {
                cout << curr << ' ';
            } else {
                curr = (curr%2)+1;
                cout << curr << ' ';
            }
        }
    } else if (wow) {
        cout << 2 << '\n';
        int curr = 1;
        cout << 1 << ' ';
        int flag = 0;
        for (int i = 1; i < n; i++) {
            if (i == n-1 && lasto) {
                cout << 1 << ' ';
                break;
            }
            if (type[i] == type[i-1] && flag == 0) {
                cout << curr << ' ';
                flag = 1;
            } else {
                curr = (curr%2)+1;
                cout << curr << ' ';
            }
        }
    } else {
        cout << 3 << '\n';

        int curr = 0;
        for (int i = 0; i < n-1; i++) {
            curr = (curr%3)+1;
            cout << curr << ' ';
        }
        if (curr == 2) {
            cout << 3;
        } else if (curr == 1) {
            cout << 2;
        } else {
            cout << 2;
        }

    }

    cout << '\n';
    
}





