// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>>ansMap;
        for(int i=0;i<strs.size();i++)
        {
            vector<int>alphabets(26,0);
            string temp=strs[i];
            for(char i : temp)
            {
                alphabets[i-'a']++;
            }
            ansMap[alphabets].push_back(temp);
        }
        vector<vector<string>>ans;
        for(auto it:ansMap){
            ans.push_back(it.second);
        }
        return ans;
    }
};