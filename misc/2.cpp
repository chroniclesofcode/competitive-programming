#include <bits/stdc++.h>

using namespace std;

void solve();


#define LL long long
int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    solve();
}

void solve() {
    LL n, m;
    cin >> n >> m;

    LL rocks[n];
    
    for (LL i = 0; i < n; i++) {
        cin >> rocks[i];
    }
    sort(rocks, rocks+n);

    LL energy = 0;
    
    for (LL i = 1; i < n; i++) {
        energy += (rocks[i] - rocks[i-1]) * i;
        //cout << rocks[i] << " " << energy << endl;
    }
    energy += (m - rocks[n-1]) * n;

    cout << energy << '\n';
}
   
