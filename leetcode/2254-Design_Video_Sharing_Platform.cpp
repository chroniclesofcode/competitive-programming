class VideoSharingPlatform {
public:
    int id_ct = 0;
    set<int> removed;
    struct Video {
        Video() = default;
        Video(int id_, string data_) : id{id_}, data{data_} {}
        int id;
        int likes = 0, dislikes = 0;
        int views = 0;
        string data;
    };
    unordered_map<int, Video> videos;
    
    VideoSharingPlatform() {
        
    }

    bool vidExists(int videoId) {
        return videos.find(videoId) != videos.end();
    }
    
    int upload(string video) {
        int nid = 0;
        if (removed.size()) {
            nid = *removed.begin();
            removed.erase(nid);
        } else {
            nid = id_ct++;
        }
        Video v(nid, video);
        videos[nid] = std::move(v);
        return nid;
    }
    
    void remove(int videoId) {
        if (!vidExists(videoId)) return;
        videos.erase(videoId);
        removed.insert(videoId);
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if (!vidExists(videoId)) return "-1";
        auto &v = videos[videoId];
        v.views++;
        return v.data.substr(startMinute, endMinute-startMinute+1);
    }
    
    void like(int videoId) {
        if (!vidExists(videoId)) return;
        auto &v = videos[videoId];
        v.likes++;
    }
    
    void dislike(int videoId) {
        if (!vidExists(videoId)) return;
        auto &v = videos[videoId];
        v.dislikes++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if (!vidExists(videoId)) return { -1 };
        auto &v = videos[videoId];
        vector<int> ret = {v.likes, v.dislikes};
        return ret;
    }
    
    int getViews(int videoId) {
        if (!vidExists(videoId)) return -1;
        auto &v = videos[videoId];
        return v.views;
    }
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */
