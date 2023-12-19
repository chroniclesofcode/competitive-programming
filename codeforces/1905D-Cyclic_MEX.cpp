#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = (LL)1e9 + 100;
constexpr LL LINF = LLONG_MAX / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;
#define arr array<LL,2>

void solve() {
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL zero = 0;
    while (zero < n && a[zero] != 0) {
        zero++;
    }
    rotate(a.begin(), a.begin() + zero + 1, a.end());
    LL ans = n;
    LL sum = n;
    deque<arr> dq; // VALUE, LENGTH OF VALUES
    for (LL i = 0; i < n-1; i++) {
        LL len = 1;
        while (!dq.empty() && dq.back()[0] > a[i]) {
            sum -= dq.back()[0] * dq.back()[1];
            len += dq.back()[1];
            dq.pop_back();
        }
        sum += a[i] * len;
        dq.push_back({a[i],len});
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}

/*
    GREEDY MONOTONIC QUEUE - you have to find a tricky math way
    to solve it, no way around it. In this case, it should be
    fairly logical to understand that everything before 0, will
    have 0 as the mex. So 0 is the key. Now you want to try some
    sort of queue that will start 0 at the end, since that's the
    simplest solution for now. Then... what happens when you
    cyclic shift? 

    So first, rotate 0 to the end, so you know the answer at
    the beginning is just n. Then, pop off the front (say x) and 
    pretend you added it to the end. What will the sum be?
    You know that since we are dealing with a full array,
    every single number will be in the list EXCEPT for x, which is
    at the very end. So therefore, it will be 1 + x (1 from the 0).
    If the next number y is popped off, and it's greater than x, you
    will realise that you will have every number now except for y,
    which is at the end. So it will be 1 + x + y. It will not affect
    x's calculation because even if you pop it off, x will be the
    mex.

    However, if you pop off the front z and it's smaller than x -
    it WILL affect x's calculation, because x will no longer be
    the mex in this rotation for it's poLL! So, you will need to
    actually pop x off THE BACK OF YOUR DEQUEUE. It's no longer 
    useful since z is going to the mex since it's under x... So
    the mex for the value of x is actually going to be z. And so
    is y - since y is always above z. So now the answer will be
    1 + 2*z + n.

    1st iteration: 4 5 2 3 6 7 0 1 (cost is 1 + 8)
    2nd iteration: 5 2 3 6 7 0 1 4 (cost is 1 + 4 + 8)
    3rd iteration: 2 3 6 7 0 1 4 5 (cost is 1 + 4 + 5 + 8)
    4th iteration: 3 6 7 0 1 4 5 2 (cost is 1 + 3 * 2 + 8)

    Don't get confused -> it's a bit confusing but the costs are actually
    shifted left of what they actually are... so the MEX of 0 is 1, the
    MEX of 1 is going to be 4 (for 3rd it, 2 for 4th it). The last one
    will ALWAYS be n. Despite this, you can just visualise each number
    being it's own MEX (and of course, it is only if there is no rightmost
    larger number -> otherwise you take that value instead!)

    NOTE: if you don't pair up the dupes with a pair, it will TLE
    because imagine if you replace everything smaller than it 
    with the actual number.. e.g. 2 replaces everything.. the next
    one will be 1, the 1 will need to replace all the 2s! This
    is exponential.
*/

// MEX CALCULATION FOR KNOWLEDGE
/*
    vector<LL> mi(n+2);
    LL ans = 0;
    LL mex = 0;
    for (LL i = 0; i < n; i++) {
        mi[a[i]]++;
        while (mi[mex]) {
            mex++;
        }
        ans += mex;
    }
    cout << ans << '\n';
*/






