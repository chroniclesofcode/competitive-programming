class Solution {
public:
    vector<string> ans;
    string curr;
    void gen(int left, int right) {
        if (left == 0 && right == 0) {
            ans.push_back(curr);
            return;
        }
        if (left > 0) {
            curr.push_back('(');
            gen(left-1, right+1);
            curr.pop_back();
        }
        if (right > 0) {
            curr.push_back(')');
            gen(left, right-1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        gen(n, 0);
        return ans;
    }
};
