class Solution {
public:
    int convert(int x) {
        int rx = 0;
        while (x) {
            rx <<= 1;
            if (x & 1) {
                rx ^= 1;
            }
            x >>= 1;
        }
        return rx;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [this](const int &a, const int &b) {
            int ca = convert(a), cb = convert(b);
            if (ca == cb) return a < b;
            return ca < cb;
        });
        return nums;
    }
};