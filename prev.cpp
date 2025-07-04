#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q, w;


void solve() {
    cin >> n >> w;
    vector<arr3> blocks(n);
    unordered_map<int,int> ordering;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        blocks[i] = {y-1, x-1, i};
    }
    cin >> q;
    vector<arr3> queries(q);
    for (int i = 0; i < q; i++) {
        int t, a; cin >> t >> a;
        queries[i] = {t, a-1, i};
    }
    sort(queries.begin(), queries.end());
    sort(blocks.begin(), blocks.end());
    int j = 0;
    vector<int> filled(n+1, 0); // how many in each vertical level?
    vector<int> horiz(n+1, 0); // how many each horiz column?
    vector<int> ans(q);
    for (auto &[time, bnum, ansi] : queries) {
        while (j < n && blocks[j][0] < time) {
            int xblock = blocks[j][1];
            ordering[blocks[j][2]] = horiz[xblock];
            filled[horiz[xblock]]++;
            horiz[xblock]++;
            j++;
        }
        if (ordering.find(bnum) != ordering.end() && filled[ordering[bnum]] >= w) {
            ans[ansi] = 0;
        } else {
            ans[ansi] = 1;
        }
    }
    for (int i = 0; i < q; i++) {
        if (ans[i]) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << '\n';
    }
}

/*

*/