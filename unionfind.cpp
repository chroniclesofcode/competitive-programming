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
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

int size[MX];
int group[MX]; 

int Find(int a) {
    if (a == group[a]) {
        return a;
    }
    return group[a] = Find(group[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) {
        if (size[a] < size[b]) {
            swap(a, b);
        }
        group[b] = a;
        size[a] += size[b];
    }

}

int n;

/*

*/

void solve() {

}





