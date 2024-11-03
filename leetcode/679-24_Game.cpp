class Solution {
public:
    /*
    backtracking, 
    */
    int used[5];
    bool reached = false;
    vector<int> curr;

    vector<double> combine(double a, double b) {
        return {a/b, b/a, a+b, a-b, b-a, a*b};
    }

    void operators() {
        double eps = 1e-4;
        double a = curr[0], b = curr[1], c = curr[2], d = curr[3];
        for (auto x: combine(a, b))
                for (auto y: combine(c, d))
                    for (auto z: combine(x, y)) 
                        if (abs(z - 24) < eps) {
                            reached = true;
                            return;
                        }
            for (auto x: combine(a, b))
                for (auto y: combine(c, x))
                    for (auto z: combine(d, y))
                        if (abs(z - 24) < eps) {
                            reached = true;
                            return;
                        }
    }
    void bt(vector<int> &cards) {
        if (reached) return;
        if (curr.size() == 4) {
            operators();
            return;
        }
        for (int i = 0; i < cards.size(); i++) {
            if (used[i]) continue;
            curr.push_back(cards[i]);
            used[i] = true;
            bt(cards);
            used[i] = false;
            curr.pop_back();
        }
    }
    
    bool judgePoint24(vector<int>& cards) {
        bt(cards);
        return reached;
    }
};
