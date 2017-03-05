#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 
10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by 
users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        id_news_q[userId].push_back(make_pair(time++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        deque<int> dq = mergeQ(userId, id_news_q);
        vector<int> res(dq.size());
        int Nsize = dq.size();
        for (int i = 0; i < Nsize; i++) {
            res[i] = dq.front(); 
            dq.pop_front();
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followers.find(followerId) == followers.end()) return;
        if (followers[followerId].find(followeeId) != followers[followerId].end())
            followers[followerId].erase(followeeId);
    }
private:
    int time = 0;
    unordered_map<int, deque<pair<int, int>>> id_news_q;
    unordered_map<int, unordered_set<int>> followers;
    

    deque<int> mergeQ(int userId, unordered_map<int, deque<pair<int, int>>> id_news_q) { // faster if we use reference, but take care to set data back
        unordered_map<int, int> cnt_user_tweets;
        for (auto c : id_news_q)
            if (userId == c.first || followers[userId].find(c.first) != followers[userId].end())
                cnt_user_tweets[c.first] = id_news_q[c.first].size();

        int total_cnt = 0;
        deque<int> res;
        while (1) {
            int most_recent = -1;
            int cur_tweet = -1;
            int cur_user = -1;
            for (auto c: cnt_user_tweets) {
                // use heap would be much faster, https://discuss.leetcode.com/topic/48253/72ms-c-solution
                /*auto f = [](const std::pair<Tweet*, Tweet*>& x, const std::pair<Tweet*, Tweet*>& y) {
                    return x.second->time < y.second->time;
                };
                std::make_heap(h.begin(), h.end(), f);*/
                if (cnt_user_tweets[c.first] > 0 && id_news_q[c.first].back().first > most_recent) { 
                    most_recent = id_news_q[c.first].back().first;
                    cur_tweet = id_news_q[c.first].back().second;
                    cur_user = c.first;
                }                
            }
            if (cur_tweet != -1) {
                    res.push_back(cur_tweet);
                    total_cnt++;
                    cnt_user_tweets[cur_user]--;
                    id_news_q[cur_user].pop_back();
            }
            int if_rest_news = 0;
            for (auto c: cnt_user_tweets) if_rest_news += cnt_user_tweets[c.first];
                    
            if (total_cnt == 10 || if_rest_news == 0) break;
        }
        return res;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */


int main() {
    Examples eg;
    Twitter obj;
    obj.postTweet(2, 5);
    obj.postTweet(1, 3);
    obj.postTweet(1, 101);
    obj.postTweet(2, 13);
    obj.postTweet(2, 10);
    obj.postTweet(1, 2);
    obj.postTweet(2, 94);
    obj.postTweet(2, 505);
    obj.postTweet(1, 333);
    obj.postTweet(1, 3);
    print(obj.getNewsFeed(2));

    obj.follow(2, 1);
    print(obj.getNewsFeed(2));
}
