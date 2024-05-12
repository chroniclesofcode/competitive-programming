class Solution {
public:
    int n; 
    int res = INT_MAX;
    int used[15];
    int mp[15];
    vector<int> ans;
    vector<int> nums;
    vector<int> perm;
    void dfs(int score) {
        
        if (perm.size() == n) {
            score += abs(perm.back() - nums[perm[0]]);
            if (score < res) {
                res = score;
                ans = perm;
            }
            return;
        }
        for (int i = 0; i <= n-1; i++) {
            if (!used[i]) {
                int push = score + abs(perm.back() - nums[i]);
                if (push >= res) continue;
                perm.push_back(i);
                used[i] = 1;
                dfs(push);
                perm.pop_back(); 
                used[i] = 0;
            }
        }
    }
    vector<int> findPermutation(vector<int>& _nums) {
        nums = std::move(_nums);
        n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        perm.push_back(0); used[0] = 1;
        dfs(0);
        return ans;
    }
};
