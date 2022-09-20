#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void solve() {  
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<pair<int, int>> paths;
    paths.push_back({0, n-1});

    int val = a[0] + a[n-1];

    // Set front and back to be the same
    // so we can turn every value in the array
    // to be the same...
    if (val % 2 == 0) {
        a[0] = a[n-1];
    } else {
        a[n-1] = a[0];
    }

    for (int i = 1; i < n-1; i++) {
        if ((a[i] + a[0]) % 2 == 0) {
            paths.push_back({i, n-1});
        } else {
            paths.push_back({0, i});
        }
    }

    cout << paths.size() << '\n';

    for (auto path : paths) {
        auto a = path.first;
        auto b = path.second;
        cout << a+1 << " " << b+1 << '\n';
    }

}

