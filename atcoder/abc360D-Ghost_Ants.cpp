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

LL n, m, k;
vector<LL> a;

long long mergeAndCount(vector<LL>& arr, vector<LL>& temp, LL left, LL mid, LL right) {
    LL i = left;
    LL j = mid + 1;
    LL k = left;
    long long inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long mergeSortAndCount(vector<LL>& arr, vector<LL>& temp, LL left, LL right) {
    long long inv_count = 0;
    if (left < right) {
        LL mid = (left + right) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

long long countInversions(vector<LL>& arr) {
    vector<LL> temp(arr.size());
    return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

void solve() {
    cin >> n >> k;
    string s; cin >> s;
    vector<pair<LL,LL>> x;
    for (LL i = 0; i < n; i++) {
        LL e; cin >> e;
        x.push_back({e, i});
    }
    sort(x.begin(), x.end());
    for (LL i = 0; i < n; i++) {
        LL idx = x[i].second;
        LL val = x[i].first;
        if (s[idx] == '0') val -= k;
        else if (s[idx] == '1') val += k;
        x[i] = {val, i};
    }
    sort(x.begin(), x.end());
    LL ans = 0;
    for (LL i = 0; i < n; i++) {
        a.push_back(x[i].second);
        if (i > 0 && x[i].first == x[i-1].first) {
            ans++;
        }
    }
    ans += countInversions(a);
    cout << ans << '\n';
}

/*

*/

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/

