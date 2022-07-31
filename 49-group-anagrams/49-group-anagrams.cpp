class Solution {
public:
    vector<vector<string>>ans;
    
    void solver(vector<string>& strs)
    {
        unordered_map<string,vector<string>>ump;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            ump[temp].push_back(strs[i]);
        }
        for(auto it:ump)
        {
            ans.push_back(it.second);
        }
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        solver(strs);
        return ans;
        // map<vector<int>,vector<string>>mp;
        // //or make an unordered map in which u make a copy of string at each iteration and push the string in unorderred map of string and vector based on the sorted copy string
        // //
        // for(auto i:strs)
        // {
        //     vector<int>freq(26,0);
        //     for(int j=0;j<i.size();j++)
        //     {
        //        freq[i[j]-'a']++;
        //     }
        //     mp[freq].push_back(i);
        // }
        // vector<vector<string>>ans;
        // for(auto it:mp)
        //     ans.push_back(it.second);
        // return ans;
        // SC : o(nk)  as k is the size of string and n is array length
    }
};