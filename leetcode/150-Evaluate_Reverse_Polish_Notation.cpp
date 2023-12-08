class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& s : tokens) {
            if (s.size() == 1 && !isdigit(s[0])) {
              int n1 = st.top(); st.pop();
              int n2 = st.top(); st.pop();
              if (s[0] == '+') {
                st.push(n1+n2);
              } else if (s[0] == '-') {
                st.push(n2-n1);
              } else if (s[0] == '/') {
                st.push(n2/n1);
              } else if (s[0] == '*') {
                st.push(n1*n2);
              }
            } else {
              st.push(stoi(s));
            }
        }
        return st.top();
      }
};
