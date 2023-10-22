class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> ct;
        vector<int> a;
        for (auto i : nums) {
            ct[i]++;
        }
        int run = INT_MAX;
        for (auto p : ct) {
            run = min(run, p.second);
            a.push_back(p.second);
        }
        int ans = INT_MAX;
        for (int i = 1; i <= run; i++) {
            bool flag = true;
            int f1 = i, f2 = i+1;
            int add = 0;
            for (int j = 0; j < a.size(); j++) {
                int tmp = a[j];
                int small = INT_MAX; int gsz = 0;
                while (tmp >= 0) {
                    if (tmp % f1 == 0) small = gsz + tmp / f1;
                    tmp -= f2;
                    gsz++;
                }
                if (small == INT_MAX) {
                    flag = false;
                    break;
                }
                add += small;
            }
            if (flag) ans = min(ans, add);
        }
        return ans;
    }
    
};
