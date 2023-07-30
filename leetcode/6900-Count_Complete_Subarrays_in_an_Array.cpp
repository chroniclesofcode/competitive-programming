class Solution {
public:
    unordered_map<int, int> m;
    int countCompleteSubarrays(vector<int>& nums) {
        
        int dis = 0;
        for (auto &e : nums) {
            if (m[e] == 0) {
                dis++;
                m[e]++;
            } 
        }
        int n = nums.size();
        int ans = 0;
        for (int i = dis; i <= n; i++) {
            m.clear();
            int distinct = 0;
            
            for (int j = 0; j < n; j++) {
                if (j >= i) {
                    m[nums[j-i]]--;     
                    if (m[nums[j-i]] == 0) {
                        distinct--;
                    }
                    //cout << "deleted elem: " << j - i << " dist now: " << distinct << '\n';
                }
                if (m[nums[j]] == 0) {
                    distinct++;
                }
                m[nums[j]]++;
                if (j >= i-1 && distinct == dis) {
                    ans++;
                }
                //cout << "distinct: " << distinct << " size: " << i << " j: " << j << endl;
            } 
        }
        return ans;

    }
};
