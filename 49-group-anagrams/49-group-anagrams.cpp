class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        for(auto i:strs)
        {
            vector<int>freq(26,0);
            for(int j=0;j<i.size();j++)
            {
               freq[i[j]-'a']++;
            }
            mp[freq].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
    }
};