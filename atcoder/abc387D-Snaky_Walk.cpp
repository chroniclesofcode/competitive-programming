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

int n, m, k, q;

bool check(int i, int j, int h, int w, vector<string> &grid) {
    return i >= 0 && j >= 0 && i < h && j < w && grid[i][j] != '#';
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    array<int,2> st, fin;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        grid[i] = s;
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 'S') {
                st = {i, j};
            } else if (grid[i][j] == 'G') {
                fin = {i, j};
            }
        }
    }
    vector<int> vdist(h * w, INT_MAX); // min dist on square, moving vert
    vector<int> hdist(h * w, INT_MAX); // min dist on square, moving horiz
    queue<array<int, 4>> q; // i, j, 0 if vert, 1 if horiz, dist
    q.push({st[0], st[1], 0, 0});
    q.push({st[0], st[1], 1, 0});
    while (!q.empty()) {
        auto [i, j, is_horiz, dist] = q.front();
        q.pop();
        int id = i*w + j;
        if (is_horiz) {
            if (hdist[id] <= dist) {
                continue;
            }
            hdist[id] = dist;
            if (check(i, j+1, h, w, grid)) {
                q.push({i, j+1, !is_horiz, dist+1});
            }
            if (check(i, j-1, h, w, grid)) {
                q.push({i, j-1, !is_horiz, dist+1});
            }
        } else {
            if (vdist[id] <= dist) {
                continue;
            }
            vdist[id] = dist;
            if (check(i+1, j, h, w, grid)) {
                q.push({i+1, j, !is_horiz, dist+1});
            }
            if (check(i-1, j, h, w, grid)) {
                q.push({i-1, j, !is_horiz, dist+1});
            }
        }
    }
    int ansid = fin[0]*w + fin[1];
    int ans = min(vdist[ansid], hdist[ansid]);
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

/*

*/