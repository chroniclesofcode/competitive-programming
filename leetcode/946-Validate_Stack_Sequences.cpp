class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        int m = popped.size();
        for (int i = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while (!s.empty() && j < m && popped[j] == s.top()) {
                s.pop();
                j++;
            }
        }
        if (s.empty() && j >= m) return true;
        return false;
    }
};
