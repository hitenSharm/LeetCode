class Solution {
public:
#define ll long long int
    bool valid(vector<int>& a1, vector<int>& a2)
    {
        double aa = a1[0] * 1.0;
        double bb = a1[1] * 1.0;
        double xx = a2[0] * 1.0;
        double yy = a2[1] * 1.0;
        double r1 = a1[2] * 1.0;
        double r2 = a2[2] * 1.0;
        double dist = sqrt((aa - xx) * (aa - xx) + (bb - yy) * (bb - yy));
        if (dist < r1 + r2)return true;

        return false;
    }
    unordered_map<int, vector<int>>adj;
    vector<int>vis;

    int dfs(int node)
    {
        int nodes = 0;
        vector<int>& candi = adj[node];
        for (auto i : candi)
        {
            if (vis[i] == 1)continue;
            vis[i] = 1;
            nodes += 1 + dfs(i);
        }
        return nodes;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
         for(int i=0;i<n;i++)
        {
            ll x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                     ll x2,y2,r2;
                     x2=abs(x1-bombs[j][0]);
                     y2=abs(y1-bombs[j][1]);
                    if(x2*x2+y2*y2<=r1*r1)
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        vis.resize(bombs.size(), 0);
        int ans = 0;
        for (int i = 0; i < bombs.size(); i++)
        {
            vis=vector(bombs.size(),0); //as the question invlove
            //getting the center inside range => 1->2 doesent neccesarily means 2->1
            vis[i] = 1;
            ans = max(ans,1 + dfs(i));
        }
        return ans;
    }
};