// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:    
    static bool cmp(pair<string,int>& a,pair<string,int>& b)
    {
        if(a.second!=b.second)
            return (a.second>b.second);
        return (a.first<b.first);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>ump;
        
        for(int i=0;i<words.size();i++)
            ump[words[i]]++;
        
        vector<pair<string,int>>vec;
        for(auto it:ump)
        {
            vec.push_back({it.first,it.second});
        }
        partial_sort(vec.begin(),vec.begin()+k,vec.end(),cmp);
        vector<string>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};