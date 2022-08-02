class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        //bfs from each gat and a level order traversal
        queue<pair<int,int>>q;
        for(int i=0;i<rooms.size();i++)
        {
            for(int j=0;j<rooms[0].size();j++)
            {
                if(rooms[i][j]==0){
                    q.push({i,j});                    
                }
            }
        }
        int level=1;
        int dirs[5]={-1,0,1,0,-1};
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                pair<int,int> p = q.front();
                q.pop();
                int i=p.first,j=p.second;
                for(int k=0;k<4;k++)
                {      
                    int ni=i+dirs[k];
                    int nj=j+dirs[k+1];
                    if(ni>=0 and nj>=0 and ni<rooms.size() and nj<rooms[0].size() and rooms[ni][nj]!=-1 and rooms[ni][nj]!=0)
                    {
                        if(rooms[ni][nj]>level)
                        {
                            rooms[ni][nj]=level;
                            q.push({ni,nj});
                        }
                    }
                }
            }
            level++;
        }
    }
};