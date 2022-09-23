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
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    /*
    dp[elem][time]
    for every single value in the array that we are up to
    we will traverse every single time and hypothetically
    add a[i] to it. Realistically, some of these times may
    never actually be reached by adding a[i], but we say we 
    do so anyways in case
    */

    vector<vector<int>> dp(n+10, vector<int>(h+10, 0));

    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < h; j++) {
            int t1 = (j + a[i]) % h;
            int bit = 0;
            if (t1 >= l && t1 <= r) {
                bit = 1;
            }
            dp[i][j] = bit + dp[i+1][t1];

            int t2 = (j + a[i] - 1) % h;
            int bit2 = 0;
            if (t2 >= l && t2 <= r) {
                bit2 = 1;
            }
            dp[i][j] = max(dp[i][j], bit2 + dp[i+1][t2]);
        }
    }

    cout << dp[0][0] << endl;

    
}

