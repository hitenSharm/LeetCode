// https://leetcode.com/problems/video-stitching

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

    int recu(vector<vector<int>>& clips,int& t,int s,int e,int index)
    {
        if(index>=clips.size())return 0;
        if(clips[index][1]>=t)return 1;
        
        int ans=101;
        if(s==-1)
        {
            for(int i=index;i<clips.size();i++)
            {
                if(clips[i][0]==0)
                {
                    ans=min(ans,1+recu(clips,t,clips[i][0],clips[i][1],i+1));
                }
                else
                break;
            }
        }
        else
        {
            for(int i=index;i<clips.size();i++)
            {
                if(clips[i][0]==s)continue;
                if(clips[i][0]<=e)
                {
                    ans=min(ans,1+recu(clips,t,clips[i][0],clips[i][1],i+1));
                }
                else
                break;
            }
        }
        return ans;
    }

    int videoStitching(vector<vector<int>>& clips, int t){
        sort(clips.begin(),clips.end());
        int start=-1,en=-1;
        int sol=recu(clips,t,start,en,0);
        if(sol>=100)
        return -1;
        return sol;
    }
};