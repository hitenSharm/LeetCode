#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    
    int calc(vector<int>& st,vector<int>& me)
    {
        int cnt=0;
        for(int i=0;i<st.size();i++)
        {
            if(me[i]==st[i])cnt++;
        }
        return cnt;
    }
    
    int recu(vector<vector<int>>& students, vector<vector<int>>& mentors,int i,vector<int>vis)
    {
        if(i>=students.size())return 0;
        int ans=INT_MIN;
        
        for(int j=0;j<mentors.size();j++)
        {
            if(vis[j]==1)continue;
            vis[j]=1;
            int temp=calc(students[i],mentors[j]);
            ans=max(ans,temp+recu(students,mentors,i+1,vis));
            vis[j]=0;
        }
        return ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<int>vis(mentors.size(),0);
        return recu(students,mentors,0,vis);
    }
};