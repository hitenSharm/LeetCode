class Solution {
public:

    bool subChk(string s,unordered_map<string,int>& ump)
    {        
        for(int i=0;i<s.length();i++)
        {
            string s1=s;
            s1.erase(i,1);
            if(ump.find(s1)!=ump.end())return true;
        }
        return false;
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int ans=0;
        unordered_map<string,int>ump;
        for(int j=0;j<startWords.size();j++)
        {
            sort(startWords[j].begin(),startWords[j].end());
            ump[startWords[j]]++;
        }
        for(int i=0;i<targetWords.size();i++)
        {
            string& s=targetWords[i];
            sort(s.begin(),s.end());
            if(subChk(s,ump))ans++;
        }
        return ans;
    }
};