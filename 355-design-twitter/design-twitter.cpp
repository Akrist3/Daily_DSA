class Twitter {
private:
    int timer;    
    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;
    // user -> set of followees
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() {
        timer = 0;
    }    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }    
    vector<int> getNewsFeed(int userId) {
        // max heap -> {time, tweetId, userId, index}
        priority_queue<tuple<int,int,int,int>> pq;
        
        // user follows himself
        following[userId].insert(userId);
        // push latest tweet of each followee
        for(auto followee : following[userId]) {
            if(tweets.count(followee) && !tweets[followee].empty()) {
                int lastIndex = tweets[followee].size() - 1;
                auto [time, tweetId] = tweets[followee][lastIndex];
                pq.push({time, tweetId, followee, lastIndex});
            }
        }
        vector<int> feed;
        while(!pq.empty() && feed.size() < 10) {
            auto [time, tweetId, user, index] = pq.top();
            pq.pop();
            
            feed.push_back(tweetId);
            // push previous tweet of same user
            if(index > 0) {
                auto [t, id] = tweets[user][index - 1];
                pq.push({t, id, user, index - 1});
            }
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.count(followerId))
            following[followerId].erase(followeeId);
    }
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */