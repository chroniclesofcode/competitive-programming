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

int n;

/*

*/

void solve() {

}

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1001][1001];
        // dp[i][j] is longest common subarray ending on i for nums1 and j for nums2.
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] != nums2[j]) {
                    dp[i][j] = 0;
                } else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};



