#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prLL_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr LL INF = (LL)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, q;

void solve() {
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<LL>> vq(n+1);
    for (LL i = 0; i < n; i++) {
        vq[a[i]].push_back(i);
    }
    long long ans = 0;
    for (LL i = 0; i < n; i++) {
        vector<LL> &q = vq[i];
        vector<LL> &nq = vq[i+1]; // possible because n+1
        LL sz = q.size();
        for (LL j = 0; j < sz; j++) {
            // find sandwiched indices in next_queue
            auto it = lower_bound(nq.begin(), nq.end(), q[j]);
            LL right = (it == nq.end() ? n : *it);
            LL rbound = (j < sz-1 ? q[j+1] : n);
            right = min(right, rbound);
            LL left = -1;
            if (it != nq.begin()) {
                it--;
                left = *it;
            }
            ans += (q[j] - left) * (right - q[j]);
        }
    }
    cout << ans << '\n';
}

/*
let's say we union find everything together that is of the same
group, and give everyone a group ID. So now the question is
given an array of LLegers from 1->N with repeats, for every
subarray, what is the number of distinct LLegers?

We can somehow iterate through the indices of each number and
get a better understanding, I think.

count no of pairs where j is in the array and j+1 is not in the array
this will give you all the 'runs'.
Now count for all subarrays

What could hLL me of this question???
*/