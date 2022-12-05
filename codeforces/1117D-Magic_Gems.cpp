#include <bits/stdc++.h>
#include <fstream>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 101;
const LL MOD = 1e9 + 7;

LL N, M;

struct Matrix {
    LL a[MX][MX];

    Matrix() {
        memset(a, 0, sizeof(a));
    }

    static Matrix getIdentity() {
        Matrix res;
        for (LL i = 0; i < M; i++) {
            res.a[i][i] = 1;
        }
        return res;
    }

    Matrix operator *(Matrix o) {
        Matrix res;
        for (LL i = 0; i < M; i++) {
            for (LL j = 0; j < M; j++) {
                for (LL k = 0; k < M; k++) {
                    res.a[i][k] += a[i][j] * o.a[j][k];
                    res.a[i][k] %= MOD;
                }
            }
        }
        return res;
    }

    Matrix operator^(LL k) {
        Matrix res = Matrix::getIdentity();
        Matrix a = *this;
        while (k) {
            if (k&1) {
                res = res*a;
            }
            a = a*a;
            k /= 2;
        }
        return res;
    }
};

// Dp[i] represents ways to arrange using n spaces
// dp[i] = dp[i-1]+dp[i-m];
// surprisingly, no bugs...

void solve() {
    cin >> N >> M;

    Matrix res;
    res.a[0][0] = 1;
    res.a[0][M-1] = 1;
    for (LL i = 1; i < M; i++) {
        res.a[i][i-1] = 1;
    }
    res = res^N;
    cout << res.a[0][0] << '\n';

}



