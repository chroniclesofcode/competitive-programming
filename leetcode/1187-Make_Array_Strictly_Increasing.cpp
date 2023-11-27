class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        constexpr int inf = (int)1e9 + 10;
        // sort and make arr2 unique
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        // initialise 2 dps, keep: 0..i, not-swapping arr1[i]
        // exch: min cost if swap i with arr2[j].
        int n = arr1.size(), m = arr2.size();
        vector<int> keep(n, inf);
        vector<vector<int>> exch(n, vector<int>(m, inf));
        // base cases
        keep[0] = 0;
        for (int i = 0; i < m; i++) exch[0][i] = 1;
        // Main loop, don't run for i = 0.
        for (int i = 1; i < n; i++) {
            // these will be running vals for keeping/swapping
            // we are testing swap/keeps for all combinations to find mins
            int mine = inf;
            int mink = inf;
            for (int j = 0; j < m; j++) {
                if (i > 0 && j > 0) {
                    // swap current i to j, force 0..i-1 to j-1 -> smaller
                    mine = min(mine, exch[i-1][j-1]+1);
                }
                if (i > 0) {
                    // no need to swap, can exchange i-1 as j since bigger
                    if (arr1[i] > arr2[j]) mink = min(mink, exch[i-1][j]);
                    // swap curr to j, since i-1 is smaller
                    if (arr2[j] > arr1[i-1]) mine = min(mine, keep[i-1]+1);
                    // don't need to do anything, just keep everything
                    if (arr1[i] > arr1[i-1]) mink = min(mink, keep[i-1]);
                }
                keep[i] = min(keep[i], mink);
                exch[i][j] = min(exch[i][j], mine);
            }
        }
        int mine = *min_element(exch[n-1].begin(), exch[n-1].end());
        int mink = keep.back();
        int ans = min(mine, mink);
        return ans >= inf ? -1 : ans;
    }
};
