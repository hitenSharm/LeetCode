// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int cnt=0;
        int n=matrix.size();
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({matrix[0][0],{0,0}});
        int vis[301][301];        
        memset(vis,sizeof(vis),0);
        
        int ans;
        while(cnt<k)
        {
                pair<int,int>temp=pq.top().second;
                ans=pq.top().first;    
                pq.pop(); 
                // cout<<ans<<endl;
                cnt++;
                if(cnt==k)break;
                if(temp.first+1<n and vis[temp.first+1][temp.second]==0)
                {                    
                    pq.push({matrix[temp.first+1][temp.second],{temp.first+1,temp.second}});
                    vis[temp.first+1][temp.second]=1;
                }
                if(temp.second+1<n and vis[temp.first][temp.second+1]==0)
                {                    
                    pq.push({matrix[temp.first][temp.second+1],{temp.first,temp.second+1}});
                    vis[temp.first][temp.second+1]=1;
                }
        }
        return ans;
    }
};