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

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int>ans(n);
        unordered_map<int, vector<pair<int,int>>>ump(n);
        //if there are 2 red paths then the first red path to reach will be the smallest
        //same for blue
        int arr[n][2];
        memset(arr,-1,sizeof(arr));
        arr[0][0]=0;
        arr[0][1]=0;
        //red->0, blue->-1
        
        for (const auto& v : red_edges) ump[v[0]].push_back({v[1], 0});
        for (const auto& v : blue_edges) ump[v[0]].push_back({v[1], 1});
        
        queue<pair<int,int>>q;
        q.push({0,1});q.push({0,0});
        
        while(!q.empty())
        {
            pair<int,int>temp=q.front();
            q.pop();
            for(int i=0;i<ump[temp.first].size();i++)
            {
                //visited check
                if(temp.second==ump[temp.first][i].second || arr[ump[temp.first][i].first][ump[temp.first][i].second] !=-1)
                continue;
                arr[ump[temp.first][i].first][ump[temp.first][i].second] = arr[temp.first][temp.second]+1;
                q.push({ump[temp.first][i].first,ump[temp.first][i].second});
            }
        }
        for(int i=0;i<n;i++)
        {
            int val = arr[i][1];
            if ((arr[i][0] < val && arr[i][0] != -1) || val == -1) {
                val = arr[i][0];
            }
            ans[i]=val;
        }
        return ans;
    }
};