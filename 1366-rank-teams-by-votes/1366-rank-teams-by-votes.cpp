class Solution {
public:
    int arr[26][26];
    
    bool comparasion(char a,char b,int i)
    {
        if(i==26)
        return a<b;
        
        if(arr[a-'A'][i]>arr[b-'A'][i])
        return true;
        
        if(arr[a-'A'][i]<arr[b-'A'][i])
        return false;
        
        return comparasion(a,b,i+1);
    }        
    
    string rankTeams(vector<string>& votes) {
        memset(arr,0,sizeof(arr));        
        for(int i=0;i<votes.size();i++)
        {
            for(int j=0;j<votes[i].size();j++)
            {
                arr[(votes[i][j]-'A')][j]++;
            }
        }
        string s = votes[0];
        sort(s.begin(), s.end(), [&](char c1, char c2){return comparasion(c1, c2, 0);});
        return s;
    }
};