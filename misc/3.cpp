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
    int n;
    cin >> n;
    vector<pair<double, string>> a(n);
    for (int i = 0; i < n; i++) {
        string s; double val;
        cin >> s >> val;
        a[i] = make_pair(val, s);
        //cout << "pair: " << s << " " << val << endl;
    }
    sort(a.begin(), a.end());
    double mindiff = numeric_limits<double>::max();
    int minidx = 0;
    for (int i = 1; i < n; i++) {
        double tmp = a[i].first - a[i-1].first;
        if (mindiff > tmp) {
            mindiff = tmp;
            minidx = i;
        }
    }

    cout << a[minidx].second << " " << a[minidx-1].second << "\n";
}
   
