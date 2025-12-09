class Solution {
public:
    vector<int> tmp;
    int p[5001];
    bool is_pali(int x) {
        tmp.clear();
        while (x > 0) {
            tmp.push_back(x & 1);
            x >>= 1;
        }
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] != tmp[tmp.size()-1-i]) return false;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        tmp = vector<int>(32, 0);
        for (int i = 0; i <= 5000; i++) {
            p[i] = is_pali(i);
        }
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (p[x]) {
                ans[i] = 0;
                continue;
            }
            for (int j = 1; j <= 5000; j++) {
                if (p[max(0, x - j)]) {
                    ans[i] = j;
                    break;
                }
                if (p[min(5000, x + j)]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};