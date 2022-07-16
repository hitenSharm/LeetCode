class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        int toChange=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int dirs[5]={-1,0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int>p = q.front();
            q.pop();
            int i=p.first,j=p.second;
            for(int k=0;k<4;k++)
            {
                int ni=i+dirs[k],nj=j+dirs[k+1];
                if(ni>=0 and nj>=0 and ni<image.size() and nj<image[0].size() and image[ni][nj]==toChange)
                {
                    image[ni][nj]=color;
                    q.push({ni,nj});
                }
            }
        }
        return image;
    }
};