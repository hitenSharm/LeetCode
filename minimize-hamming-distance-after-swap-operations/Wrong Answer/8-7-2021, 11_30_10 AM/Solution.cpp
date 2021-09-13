// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations

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

    unordered_map<int,vector<int>>adjList;
    unordered_set<int>vis;

    int dfs(int s,vector<int>& source, vector<int>& target)
    {
        stack<int>st;
        st.push(s);
        unordered_set<int>temp;
        vector<int>indexes;
        while(!st.empty())
        {
            int ele=st.top();
            st.pop();
            vis.insert(ele);temp.insert(source[ele]);
            indexes.push_back(ele);
            vector<int>& candidates=adjList[ele];
            for(int i=0;i<candidates.size();i++)
            {
                if(vis.find(candidates[i])!=vis.end())continue;
                st.push(candidates[i]);
            }
        }
        int ans=0;
        for(int i=0;i<indexes.size();i++)
        {
            if(temp.find(target[indexes[i]])==temp.end())ans++;
        }        
        return ans;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        for(int i=0;i<allowedSwaps.size();i++)
        {
            adjList[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
            adjList[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
        }
        int ham=0;
        for(int i=0;i<source.size();i++)
        {
            if(vis.find(i)!=vis.end())continue;
            ham+=dfs(i,source,target);
        }
        return ham;
    }
};