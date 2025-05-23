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
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;

void solve() {
    cin >> q;
    deque<long long> a;
    long long tot = 0;
    long long score = 0;
    long long rev_score = 0;
    long long is_rev = 0;
    long long sz = 0;
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            // cyclic shift right
            long long mov = 0;
            if (is_rev) {
                mov = a.front();
                a.pop_front();
                a.push_back(mov);
            } else {
                mov = a.back();
                a.pop_back();
                a.push_front(mov);
            }
            score -= mov * sz;
            score = score + mov + (tot - mov);
            rev_score -= mov; 
            rev_score = rev_score - (tot - mov) + mov * sz;
        } else if (op == 2) {
            // reverse, is_rev is needed for op1/3
            is_rev = !is_rev;
            swap(score, rev_score);
        } else if (op == 3) {
            int k; cin >> k;
            // append k to array
            sz++;
            score += k * sz;
            rev_score = rev_score + k + tot;
            tot += k;
            if (!is_rev) {
                a.push_back(k);
            } else {
                a.push_front(k);
            }
        }
        cout << score << '\n';
    }
}

/*
    keep track of: sum of array, size of array, score and score reverse
    if reversal: use the reverse score
    if append: update the normal score by k * index
    update the reverse score by 
*/