#include <bits/stdc++.h>

using namespace std;

#define LL long long
// generic DP, made much easier since the requirements
// as for increasing by 1 instead of increasing in general

// I had a bug where i kept track of the indices of each x
// in a hashmap, but that doesn't account for duplicates
// later in the array, which means the increasing sequence
// you output may not necessarily be correct

// Encountered some really ridiculous stuff:

// On test #35, the case was deliberately made that unordered_map
// would be TLE as all the numbers would hash into the same
// thing. This took a LONG time to debug as I thought the
// TLE was due to something else. This made the whole thing
// O(n) per operation instead of O(1).

// This was fixed via using std::map instead of std::unordered_map
// Further testing also shows that unordered_map works as long
// as you do dp.reserve(however-many-you-need); and
// dp.max_load_factor(0.25); which basically says use 1/f or 4 times
// more memory but make it faster... aka use more buckets.


int main(void) {
    LL n;
    scanf("%lld", &n);

    // Dp represents the length of the subsequence
    // IF dp[i] is the end of the subsequence.
    unordered_map<LL, LL> dp;
    dp.reserve(262144);
    dp.max_load_factor(0.25);

    // OR
    // map<LL, LL> dp;

    LL a[n];
    LL largest = 0;
    LL largest_idx = 0;

    for (int LL i = 0; i < n; i++) scanf("%lld", &a[i]);

    for (LL i = 0; i < n; i++) {
        LL x = a[i];
        dp[x] = dp[x-1] + 1;
        if (dp[x] > largest) {
            largest = dp[x];
            largest_idx = i;
        }
    }

    LL beg = a[largest_idx] - largest + 1;

    vector<LL> res;
    printf("%lld\n", largest);
    LL curr = a[largest_idx];
    for (LL i = largest_idx; i >= 0; i--) {
        if (a[i] == curr) {
            res.push_back(i);
            curr--;
        }
    }

    for (LL i = res.size() - 1; i >= 0; i--) {
        printf("%lld ", res[i]+1);
    }
    printf("\n");

    
}


