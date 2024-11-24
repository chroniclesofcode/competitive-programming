class Solution {
public:
    bool canCatch(int target, array<int,2> ahead, array<int,2> behind) {
        int diff = ahead[0] - behind[0];
        int spdiff = behind[1] - ahead[1];
        if (spdiff <= 0) return false;
        double time = diff / (double)spdiff;
        return (double)target >= (ahead[0] + time * ahead[1]);
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<array<int,2>> s;
        vector<array<int,2>> nums;
        for (int i = 0; i < position.size(); i++) {
            nums.push_back({position[i], speed[i]});
        }
        sort(nums.begin(), nums.end());
        for (auto &[pos, spd] : nums) {
            while (!s.empty() && canCatch(target, {pos,spd}, s.top())) {
                s.pop();
            }
            s.push({pos, spd});
        }
        return s.size();
    }
};
