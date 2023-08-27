class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 31; j++) {
                if (nums[i] & (1 << j)) {
                    m[j]++;
                    break;
                }
            }
        }
        int ans = 0;
        int ct = 0;
        for (int i = 0; i < 31; i++) {
            if (target & (1 << i)) {
                int j = i;
                while (j < 31 && m[j] == 0) {
                    j++;
                }
                if (j == 31) return -1;
                while (j != i) {
                    m[j]--;
                    m[j-1] += 2;
                    ans++;
                    j--;
                }
                m[i]--;
                ct += (1 << i);
            }
            m[i+1] += m[i] / 2;
            if (ct == target) {
                break;
            }
        }
        return ans;
    }
};
