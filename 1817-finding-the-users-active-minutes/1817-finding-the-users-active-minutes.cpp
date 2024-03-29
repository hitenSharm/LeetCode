class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        //calc UAM of each user
        unordered_map<int,unordered_set<int>>users;
        for(int i=0;i<logs.size();i++)
        {
            users[logs[i][0]].insert(logs[i][1]);//means user was active at this minute(logs[i][1]);
        }
        vector<int>ans(k,0);
        for(auto it:users)
        {            
            ans[it.second.size()-1]++;
        }
        return ans;
    }
};