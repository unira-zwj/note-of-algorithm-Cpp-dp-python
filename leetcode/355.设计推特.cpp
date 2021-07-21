/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

// @lc code=start

struct ListNode {
    int value;
    ListNode *next;
}

class Twitter {
private:
    vector<vector<int>> news;
    unordered_map<int, vector<int>> follow;

public:
    /** Initialize your data structure here. */
    Twitter()；
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)；
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)；
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)；
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)；
};

Twitter::Twitter() {

}

void Twitter::postTweet(int userId, int tweetId) {
    vector<int> post = {userId, tweetId};
    news.push_back(post);
}

vector<int> Twitter::getNewsFeed(int userId) {

}

void Twitter::follow(int followerId, int followeeId) {
    follow[followerId].push_back(followeeId);
}

void Twitter::unfollow(int followerId, int followeeId) {
    for (auto& f : follow[followerId]) {
        if (f == followeeId) {
            follow[followerId].erase(f);
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

