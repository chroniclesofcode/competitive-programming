class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        vector<string> strs;
        for (int n : nums) {
            strs.push_back(to_string(n));
        }
        auto cc = [](const std::string &a, const std::string &b) {
            std::string first = a + b;
            std::string second = b + a;
            if (first > second) return true;
            return false;
        };
        sort(strs.begin(), strs.end(), cc);
        for (auto &tmp : strs) {
            s += tmp;
        }
        int zero = 1;
        for (auto c : s) {
            if (c != '0') zero = 0;
        }
        if (zero) return "0";
        return s;
    }
};
