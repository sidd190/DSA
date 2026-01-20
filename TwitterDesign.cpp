#include <bits/stdc++.h>
using namespace std;

class Twitter{
    public:
        int timestamp = 0;

        struct User{
            vector<pair<int,int>> tweets;
            unordered_set<int> following;
        };

        unordered_map<int, User> users;

        Twitter() {};

        void postTweet(int userId, int tweetId) {
            users[userId].tweets.push_back({timestamp++, tweetId});
        }
        
        vector<int> getNewsFeed(int userId) {
            priority_queue<pair<int, int>> recentFeed;

            for(auto &t : users[userId].tweets){
                recentFeed.push(t);
            }

            for(int t : users[userId].following){
                for(auto &k : users[t].tweets){
                    recentFeed.push(k);
                }
            }

            vector<int> finalFeed;
            while(!recentFeed.empty() && recentFeed.size() < 10){
                finalFeed.push_back(recentFeed.top().second);
                recentFeed.pop();
            }
            return finalFeed;
        }
        
        void follow(int followerId, int followeeId) {
            if(followerId == followeeId) return;
            users[followerId].following.insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            users[followerId].following.erase(followeeId);            
        }
};


int main() {
    
    return 0;
}