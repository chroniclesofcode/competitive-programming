class Solution {
public:
    /*
        Sliding window + trie. Keep sliding until your window is within the
        correct range, e.g. nums[i] <= nums[j]*2. While we are doing this
        we are adding all the numbers to a trie. For each char, traverse
        the trie and forcefully take the max XOR, which is just bitwise opposite
        of our current number.
    */
    const static int MX = (int)1e4 * 6 * 20;
    int tr[MX][2], c[MX], idx = 1;

    void addt(int num, int val) {
        int u = 1;
        for (int i = 19; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!tr[u][bit]) {
                tr[u][bit] = ++idx;
            }
            u = tr[u][bit];
            c[u] += val;
        }
    }

    int gett(int num) {
        int u = 1;
        int res = 0;
        for (int i = 19; i >= 0; i--) {
            int bit = !((num >> i) & 1);
            if (tr[u][bit] && c[tr[u][bit]] > 0) {
                u = tr[u][bit];
                res |= (bit << i);
            } else {
                u = tr[u][!bit];
                res |= (!bit << i);
            }
        }
        return num^res;
    }

    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();
        int ans = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            addt(nums[i], 1);
            while (j < i && nums[j]*2 < nums[i]) {
                addt(nums[j], -1);
                j++;
            }
            ans = max(ans, gett(nums[i]));
        }
        return ans;
    }
};
