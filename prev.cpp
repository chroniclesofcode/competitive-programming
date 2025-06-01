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


void solve() {
    cin >> n;
    vector<pair<int,unordered_map<int,int>>> faces;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        unordered_map<int,int> occurrences;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            occurrences[a]++;
        }
        faces.push_back({k, std::move(occurrences)});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            auto &[asz, a] = faces[i];
            auto &[bsz, b] = faces[j];
            auto &u = a.size() < b.size() ? a : b;
            auto &v = a.size() < b.size() ? b : a;
            auto usz = a.size() < b.size() ? asz : bsz;
            auto vsz = a.size() < b.size() ? bsz : asz;
            double curr = 0;
            for (auto& [face, ct] : u) {
                auto it = v.find(face);
                if (it == v.end()) continue;
                curr += ((double)ct / usz) * ((double)it->second / vsz);
            }
            ans = max(ans, curr);
        }
    }

    cout << std::setprecision(15) << ans << '\n';
}

/*

*/