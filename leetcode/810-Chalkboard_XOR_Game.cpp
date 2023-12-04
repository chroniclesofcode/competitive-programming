class Solution {
public:
    bool xorGame(vector<int>& nums) {
        return std::accumulate(nums.begin(),
                nums.end(), 0, std::bit_xor<void>()) == 0 || nums.size() % 2 == 0;
    }
};
