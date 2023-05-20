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
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int prefix = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            int p = ((prefix % k) + k) % k;
            if (m[p] > 0) {
                ans += m[p];
            }
            m[p]++;
        }
        return ans;

    }
};



