class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>ump;
        for(auto i:strs)
        {
            vector<int>freq(26,0);
            for(auto j:i)
            {
                freq[j-'a']++;
            }
            string temp="";
            for(int j=0;j<26;j++)
                temp+=to_string(freq[j])+',';            
            ump[temp].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:ump)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};