class TweetCounts {
public:
    unordered_map<string, vector<int>> tweets;
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int rep = 60;
        if (freq == "minute") rep = 60;
        else if (freq == "hour") rep = 3600;
        else if (freq == "day") rep = 86400;
        vector<int> &curr = tweets[tweetName];
        int tot = (endTime-startTime)/rep + 1;
        vector<int> ans(tot);
        for (int e : curr) {
            if (e >= startTime && e <= endTime) {
                ans[(e-startTime)/rep]++;
            }
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
