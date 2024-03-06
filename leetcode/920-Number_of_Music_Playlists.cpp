class Solution {
public:
    long long dp[101][101];
    int numMusicPlaylists(int n, int goal, int repeat) {
        dp[0][0] = 1;
        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= min(n, i); j++) {
                // new j as the last one (new)
                // we will eventually end up with n songs,
                // so we can take any of the non-used songs
                // to append as the new song.
                dp[i][j] += dp[i-1][j-1] * (n-(j-1));
                // add a new playlist to already j songs
                // cannot copy last k, leaves n-k.
                if (j > repeat)
                    dp[i][j] += dp[i-1][j] * (j - repeat);
                dp[i][j] %= (int)1e9 + 7;
            }
        }
        return dp[goal][n];
    }
};
/*
    dp[i][j][k] = 0..i songs, with 0..j songs, 0..k backwards.
    on every iteration, we are adding the ith song that we
    have to use somewhere inside the playlist. We are either
    adding a new element never seen before, or one that is seen.
    
    JK it's only 2D. this is because we don't actually use
    the K -> and we don't want to iterate up only to 
    j, since j > k is actually possible. If k > j, then
    we actually cannot have another repetition of j, so we
    don't perform the second operation.
*/
