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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int start=image[sr][sc];
        image[sr][sc]=color;
        int dirs[5]={-1,0,1,0,-1};
        while(!q.empty() and start!=color)
        {
            pair<int,int>& tmp=q.front();
            for(int k=0;k<4;++k)
            {
                int nr=tmp.first+dirs[k],nc=tmp.second+dirs[k+1];
                if(nr>=0 and nc>=0 and nr<image.size() and nc<image[0].size() and image[nr][nc]==start)
                {
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
            q.pop();
        }
        return image;
    }    
};