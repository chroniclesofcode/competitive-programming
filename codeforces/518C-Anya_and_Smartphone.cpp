#include <bits/stdc++.h>

using namespace std;

#define LL long long

// Straightforward brute force, nothing special at all.

int main(void) {
    LL int n, m, k;
    cin >> n >> m >> k;
    LL menu[n];
    // Number to index
    unordered_map<LL, LL> ma;
    for (LL i = 0; i < n; i++) {
        cin >> menu[i];
        ma[menu[i]] = i;
    }
    LL count = 0;
    while (m--) {
        LL launch;
        cin >> launch;

        LL idx = ma[launch];
        count += 1 + (idx / k);
        if (idx == 0) continue;

        LL tmp = menu[idx-1];
        menu[idx-1] = menu[idx];
        menu[idx] = tmp;

        ma[launch] = idx - 1;
        ma[tmp] = idx;
    }
    cout << count << endl;
}

