class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>ump;
        for(auto i:strs)
        {
            vector<int>freq(26,0);
            for(auto j:i)
            {
                freq[j-'a']++;
            }
            ump[freq].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:ump)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};