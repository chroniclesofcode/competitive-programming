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
const LL MX = 9 * 1e5 ;
const LL MOD = 1e7;

int n, a[MX];

int r1[MX];
int r2[MX];

bool marked[MOD+1];
int primefactorization[MOD+1];

void sieve() {
    for (int i = 2; i <= MOD; i++) {
        if (!marked[i]) {
            primefactorization[i] = i;
            for (int j = 2*i; j <= MOD; j += i) {
                marked[j] = true;
                int tmp = j;
                while (tmp % i == 0) {
                    if (primefactorization[j] == 0) {
                        primefactorization[j] = i;
                    } else if (primefactorization[j] % i == 0) {
                        primefactorization[j] *= i;
                    } else {
                        break;
                    }
                    tmp /= i;
                }
            }
        }
    }
}

// Idea is we partition the divisors of the number somehow?
// if a and b are prime, nothing will divide them, and that
// means a + b cannot be divided by a or b. That means that
// a * b should theoretically be coprime with a + b because
// if they share a common divisor, it will have to be either
// a or b (which can never divide a + b [ i think ]). 
// So I should probably just choose two divisors of 
// a[i]. But for something like 70, it has 5 and 2 as a divisor
// which 7 is not coprime with 70. 
// doesn't really matter because 5 * 2 = 10, we want 70 on the
// RHS of the gcd, so we should just partition one prime with
// the other. so 2 + 5*7 should work theoretically.
// when is the case when it doesn't work? for 8 -> 2, 2, 2 doesnt
// work because it's all one divisor. 
// 2 * 2 * 5 * 7 * 11 = 1540
// I think I just take all the 2's or I take the 11. Then there's
// no way it will be even.
void solve() {
    sieve();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (primefactorization[a[i]] != a[i])  {
            r1[i] = primefactorization[a[i]];
            r2[i] = a[i] / r1[i];
        } else {
            r1[i] = -1; r2[i] = -1;
        }
    }
    for (int i = 0; i < n; i++) cout << r1[i] << " ";
    cout << '\n';
    for (int i = 0; i < n; i++) cout << r2[i] << " ";
    cout << '\n';
}





