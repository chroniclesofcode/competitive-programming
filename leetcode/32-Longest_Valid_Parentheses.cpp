class Solution {
public:
    /*
       Took a little bit of fine tuning to do, but
       in the end it was DP. At first, I tried to
       just have a last variable, and kept track of the
       minimum closure time, but ()(() would break it.

       So in this case, I just kept a DP array of lasts,
       and I noticed that when we close a bracket, if we
       want an answer that is more than 2, the element
       directly before the open ( bracket, must be a close
       bracket. Makes sense because the close bracket signifies
       another set of parentheses closing, if it's open, it means
       it actually hasn't closed yet.
    */
    int longestValidParentheses(string str) {
        stack<int> s;
        int ans = 0;
        vector<int> last(str.size(), 1e5);
        for (int i = 0; i < str.size(); i++) {
            if (s.empty() && str[i] == ')') {
                continue;
            }
            if (s.empty()) {
                s.push(i);
            } else if (str[i] == '(') {
                s.push(i);
            } else if (str[i] == ')') {
                int idx = s.top();
                s.pop();
                ans = max(ans, i - idx + 1);
                if (idx > 0) {
                    ans = max(ans, i - last[idx-1] + 1);
                    last[i] = min(idx, last[idx-1]);
                } else {
                    last[i] = 0;
                }
            }
        }
        return ans;
    }
};
