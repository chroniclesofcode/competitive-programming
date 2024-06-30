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

int n, m, k;

class Inversions {
private:
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
public:
    long long countInversions(vector<LL>& arr) {
        vector<LL> temp(arr.size());
        return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    }
};

