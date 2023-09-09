class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                m[nums[i]&nums[j]]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (auto it = m.begin(); it != m.end(); it++) {
                if ((nums[i] & it->first) == 0) {
                    ans += it->second;
                }
            }
        }
        return ans;
    }
};
