class Solution {
public:
    
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        #define ll long long
        ll MOD = 1e9 + 7;
        ll ones = 0;
        ll zeroes = 0;
        ll flag = 0;
        ll ans = 1;
        for (ll i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                flag = 1;
                ones++;
            }
            if (flag) {
                if (nums[i] == 0) {
                    zeroes++;
                } else {
                    if (i > 0 && nums[i-1] == 1) {
                    } else {
                        ans = ans * (zeroes + 1);
                        ans %= MOD;
                        zeroes = 0;
                    }
                    
                }
            } 
        }
        if (ones == 0) {
            return 0;
        } else if (ones == 1) {
            return 1;
        }

        return ans;
    }
};
