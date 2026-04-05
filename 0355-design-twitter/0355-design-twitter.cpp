#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Twitter {
private:
    int timer;
    unordered_map<int, vector<pair<int, int>>> tweets; 
    unordered_map<int, unordered_set<int>> friends;

public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
      
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<vector<int>> pq;

      
        unordered_set<int> ids = friends[userId];
        ids.insert(userId); 

        for (int id : ids) {
            if (tweets.count(id) && !tweets[id].empty()) {
                int n = tweets[id].size();
                auto lastTweet = tweets[id][n - 1];
                
                pq.push({lastTweet.first, lastTweet.second, id, n - 1});
            }
        }

        vector<int> res;
      
        while (!pq.empty() && res.size() < 10) {
            vector<int> top = pq.top();
            pq.pop();
            
            res.push_back(top[1]); 

            int uId = top[2];
            int idx = top[3];

            if (idx > 0) {
                auto prevTweet = tweets[uId][idx - 1];
                pq.push({prevTweet.first, prevTweet.second, uId, idx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
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