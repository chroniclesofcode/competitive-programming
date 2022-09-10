#include <bits/stdc++.h>

using namespace std;


#define LL long long

/*
    Quite a complex solution in order to get the
    time complexity low enough. First, we set values
    for the lowest and highest that x + y can be
    e.g. lowest -> +1, then highest = -1. So when we
    take the prefix sum of the array, it will calculate
    how many different combinations of x and y are there
    for each index. 
    Then we take the reverse prefix sum to find out how
    many combinations of x + y is GREATER than a selected
    z between c and d. We then add them to get the solution.
*/

int main(void) {
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    LL count = 0;

    int N = 1e7;

    vector<LL> arr(N, 0);

    // First array, we mark out i+b as the lowest value
    // that x + y can be.
    // i+c+1 is one higher than the highest value it can
    // be.
    for (LL i = a; i <= b; i++) {
        arr[i+b]++;
        arr[i+c+1]--;
    }

    // Prefix sum to obtain an array which stores
    // all the diff ways x + y can make a certain index
    for (LL i = 1; i <= N; i++) {
        arr[i] += arr[i-1];
    }

    // Reverse prefix sum to find out how many x + y's
    // are greater than a certain index
    for (LL i = N-2; i >= 0; i--) {
        arr[i] += arr[i+1];
    }

    // Sum them
    for (LL i = c; i <= d; i++) {
        count += arr[i+1];
    }


    cout << count << endl;
}

