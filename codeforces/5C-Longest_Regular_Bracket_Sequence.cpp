#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

int n;
stack<int> s;
string a;
/*
   
*/
void solve() {
    cin >> a;
    int ans = 0;
    int lv = -1;
    int ct = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '(') {
            s.push(i);
        } else {
            if (s.empty()) {
                lv = i;
                continue;
            }
            s.pop();
            if (s.empty()) {
                if (i - lv > ans) {
                    ans = i - lv;
                    ct = 1;
                } else if (i - lv == ans) {
                    ct++;
                }
            } else {
                if (i - s.top() > ans) {
                    ans = i - s.top();
                    ct = 1;
                } else if (i - s.top() == ans) {
                    ct++;
                }
            }
        }
    }
    cout << ans << ' ' << ct << '\n';
}





