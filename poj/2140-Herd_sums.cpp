//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define Int long long

int main(void) {

    Int n;
    cin >> n;
    Int ans = 1;
    // i represents amount of numbers in the sum
    for (Int i = 2; i < (n/2) + 1; i++) {
        Int a_sum = ((i-1) * (1 + i - 1)) / 2;
        if ((n - a_sum) % i == 0 && (n - a_sum) > 0) {
            //cout << "Pog: " <<n-a_sum<<" "<<a_sum<<" "<<i<<" a: "<<(n-a_sum)/i<<endl;
            ans++;
        }
    }
    cout << ans;
}

/*
   a + a+1 + a+2 + a+3... = n;
   4 * a = n - (1 + 2 + 3);
   If the RHS is divisible, then a solution exists.
   So for every single i to n/2 - 1, we try this.

    Note to get the RHS, we have to use the arithmetic
    sum formula which is
    n/2 * (a + L)
*/
