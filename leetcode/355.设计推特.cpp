/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */


// @lc code=start


class Twitter {
private:
    vector<vector<int>> tweetList; // userid, tewwtid
    unordered_map<int, vector<int>> followMap; // userid, followlist
    int time;
    queue<int> news;
    vector<int> userList;

public:
    /** Initialize your data structure here. */
    Twitter();
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId);
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId);
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId);
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId);
};

Twitter::Twitter() {
    time = 0;
}

void Twitter::postTweet(int userId, int tweetId) {
    bool isUserExist = false;
    for(int i=0;i<userList.size();i++){
        if(userId==userList[i]){
            isUserExist=true;
            break;
        }
    }
    if(isUserExist==false){
        userList.push_back(userId);
        followMap[userId].push_back(userId);
    }
    tweetList.push_back({userId, tweetId});
}


vector<int> Twitter::getNewsFeed(int userId) {
    vector<int> retTweet;
    if(followMap.count(userId)==0){
        return retTweet;
    }
    bool isfolloweeId;
    for(int i=tweetList.size()-1; i>=0; i--){
        isfolloweeId = false;
        for(int j=0;j<followMap[userId].size();j++){
            if(tweetList[i][0] == followMap[userId][j]){
                isfolloweeId=true;
                break;
            }
        }
        if(isfolloweeId){
            retTweet.push_back(tweetList[i][1]);
            if(retTweet.size()>=10){
                break;
            }
        }
    }
    return retTweet;
}

void Twitter::follow(int followerId, int followeeId) {
    followMap[followerId].push_back(followeeId);
}

void Twitter::unfollow(int followerId, int followeeId) {
    for(auto it=followMap[followerId].begin();it!=followMap[followerId].end();it++){
        if(*it==followeeId){
            followMap[followerId].erase(it);
            break;
        }
        
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

