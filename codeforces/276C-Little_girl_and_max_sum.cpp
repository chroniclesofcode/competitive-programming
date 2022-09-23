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
    LL n, q;
    cin >> n >> q;
    vector<LL> a(n+10, 0);
    vector<LL> b(n+10, 0);
    //vector<pair<LL, LL>> queries(q+10, 0);
    for (LL i = 0; i < n; i++) cin >> a[i];

    LL l, r;
    for (LL i = 0; i < q; i++) {
        cin >> l >> r;
        l--; r--;
        b[l]++;
        b[r+1]--;
    }

    for (LL i = 1; i < n+2; i++) {
        b[i] += b[i-1];
    }
    sort(a.begin(), a.begin()+n);
    sort(b.begin(), b.begin()+n);

    LL counter = 0;
    for (LL i = 0; i < n; i++) {
        counter += a[i] * b[i];
    }
    
    cout << counter << endl;


}

