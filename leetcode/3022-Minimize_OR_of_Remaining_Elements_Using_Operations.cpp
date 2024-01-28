class Solution {
public:
    const static int mx = (int)1e6;
    int minOrAfterOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0, ret = 0;
        for (int i = 30; i >= 0; i--) {
            int test = ans | (1 << i);
            int tmp = 0, ct = 0;
            for (auto e : nums) {
                if (tmp == 0) tmp = e & test;
                else tmp &= e & test;
                if (tmp > 0) ct++;
            }
            if (ct <= k) {
                ans = test;
            } else {
                ret |= (1 << i);
            }
        }
        return ret;
    }
};


