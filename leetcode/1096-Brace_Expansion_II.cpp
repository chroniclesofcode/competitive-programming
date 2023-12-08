class Solution {
public:
    void mult(const vector<string>& add, vector<string>& curr) {
        if (curr.size() == 0) {
            for (auto & a: add) {
                curr.push_back(move(a));
            }
            return;
        }
        vector<string> tmp;
        for (auto &i : curr) {
            for (auto &j : add) {
                tmp.push_back(i+j);
            }
        }
        swap(tmp, curr);
    }
    vector<string> process(string& expr, int beg, int end) {
        vector<string> curr;
        stack<int> s;
        int last = beg-1;
        for (int i = beg; i <= end; i++) {
            char ch = expr[i];
            if (ch == '{') {
                s.push(i);
            } else if (ch == '}') {
                s.pop();
            } else if (ch == ',') {
                if (s.size() > 0) continue;
                vector<string> tmp = process(expr, last+1, i-1);
                curr.insert(curr.end(), tmp.begin(), tmp.end());
                last = i;
            }
        }
        if (last != beg-1) {
            vector<string> tmp = process(expr, last+1, end);
            curr.insert(curr.end(), tmp.begin(), tmp.end());
            sort(curr.begin(), curr.end());
            curr.erase(unique(curr.begin(), curr.end()), curr.end());
            return curr;
        }
        s = stack<int>();
        for (int i = beg; i <= end; i++) {
            char ch = expr[i];
            if (ch == '{') {
                s.push(i); continue;
            }
            if (s.size() == 0) {
                if (isalpha(ch)) {
                    mult(vector<string>{string(1,ch)}, curr);
                }
                continue;
            }
            if (ch == '}') {
                if (s.size() == 1) {
                    mult(process(expr, s.top()+1, i-1), curr);
                }
                s.pop();
            } 
        }
        sort(curr.begin(), curr.end());
        curr.erase(unique(curr.begin(), curr.end()), curr.end());
        return curr;
    }
    vector<string> braceExpansionII(string expr) {
        return process(expr, 0, expr.size()-1);
    }
};
