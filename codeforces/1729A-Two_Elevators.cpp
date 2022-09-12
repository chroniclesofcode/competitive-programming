#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

void solve();

int main(void) {
    int t;
    cin >> t;

    while (t--) solve();

}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int t1 = a;
    int t2 = abs(b-c) + c;

    if (t1 == t2) {
        cout << 3 << endl;
    } else if (t1 > t2) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
}


