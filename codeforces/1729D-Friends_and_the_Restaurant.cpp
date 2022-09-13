#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

void solve();

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

// Sort of implementation problem?
// Find the net money contribution each person has e.g.
// y_i - x_i, then sort it, then split into positive and
// negative. Then just pair positives with negatives if
// they can go, if not then just pair positives with
// positives. In this case, you use 2 pointers.

// Code is messy, there's probably a couple of optimizations
// here and there that you can make.

void solve() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a[i] = val - a[i];
    }

    vector<int> neg, pos;
    neg.reserve(n);
    pos.reserve(n);
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            neg.push_back(a[i]);
        } else {
            pos.push_back(a[i]);
        }
    }
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    reverse(neg.begin(), neg.end());
    int sum = 0;
    int p1 = 0;
    int p2 = 0;

    int groupsize = 0;

    int ans = 0;

    while (p1 != pos.size() || p2 != neg.size()) {
        sum = 0;
        groupsize = 0; 
        while (groupsize < 2) {
           if (p1 < pos.size() && groupsize == 0) {
               sum += pos[p1];
               p1++;
               groupsize++;
           } else if (p2 < neg.size() && groupsize == 1 && sum + neg[p2] >= 0) {
               sum += neg[p2];
               p2++;
               groupsize++;
           } else if (p1 < pos.size()) {
               sum += pos[p1];
               p1++;
               groupsize++;
           } else {
               break;
           }
           if (groupsize >= 2 && sum >= 0) break;
       }
       if (sum >= 0 && groupsize >= 2) {
           ans++;
       } else {
           break;
       }
    }
    cout << ans << endl;


}


