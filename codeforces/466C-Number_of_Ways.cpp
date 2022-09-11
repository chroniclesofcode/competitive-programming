#include <bits/stdc++.h>

using namespace std;

/*

   Every time you reach S, increment S_Count by 1
   then every time you reach 2*S, answer += S_Count
   as you are able to split every S before it.

*/

#define LL long long

int main(void) {
    LL n;
    cin >> n;
    LL a[n+1];
    LL prefix[n+1];
    LL x;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        a[i] = x;
    }
    prefix[0] = a[0];
    for (LL i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }
    
    if (prefix[n-1] % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    LL split = prefix[n-1] / 3;
    LL count = 0;
    LL s_s = 0;

    for (LL i = 0; i < n-1; i++) {
        if (prefix[i] == 2 * split) {
            count += s_s;
        }
        if (prefix[i] == split) {
            s_s++;
        }
    }
    cout << count << endl;

    
}


