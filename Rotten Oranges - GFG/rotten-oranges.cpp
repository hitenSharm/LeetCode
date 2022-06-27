// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int cnt=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)cnt++;
            }
        }
        int timer=0;
        int dirs[5]={-1,0,1,0,-1};
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                pair<int,int>& p=q.front();
                for(int i=0;i<4;++i)
                {
                    if(p.first+dirs[i]>=0 and p.first+dirs[i]<grid.size() and p.second+dirs[i+1]>=0 and p.second+dirs[i+1]<grid[0].size())
                    {
                        if(grid[p.first+dirs[i]][p.second+dirs[i+1]]==1)
                        {
                            grid[p.first+dirs[i]][p.second+dirs[i+1]]=2;
                            q.push({p.first+dirs[i],p.second+dirs[i+1]});
                            cnt--;
                        }
                    }
                }
                q.pop();
            }
            timer++;
        }
        if(cnt!=0)return timer=-1;
        return timer-1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends