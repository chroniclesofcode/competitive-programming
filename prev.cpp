class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // If rook can capture in one without being blocked by the bishop
        if (a == e && !(c == a && d > min(b,f) && d < max(b,f))) return 1;
        if (b == f && !(d == b && c > min(a,e) && c < max(a,e))) return 1;
        // If bishop can capture in one without being blocked by the rook
        if (abs(c-e) == abs(d-f)) {
            bool tq1 = e-c > 0, tq2 = f-d > 0;
            bool tr1 = a-c > 0, tr2 = b-d > 0;
            bool tr3 = a-e > 0, tr4 = b-f > 0;
            if ((c == a || d == b) || !(abs(c-a)==abs(d-b))) return 1;
            if (tq1 != tr1 || tq2 != tr2) return 1;
            if (tq1 == tr3 && tq2 == tr4) return 1;
        }
        // Else, it will take 2 moves for rook to capture
        return 2;
    }
};
