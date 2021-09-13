// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int>ump;
        
        for(int i=0;i<=N;i++){
            ump[i]=0;
        }
        
        for(int i=0;i<trust.size();i++){
            ump[trust[i][0]]++;
        }
        int ans=-1;
        for(auto i:ump){
            if(i.second==0)
            {ans=i.first;
            break;
            }
        }
    return ans;
    }
};