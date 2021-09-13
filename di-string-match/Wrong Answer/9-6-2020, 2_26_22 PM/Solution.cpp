// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int siz=S.length()+1;
        int visited[siz];
        memset(visited,0,sizeof(visited));
        vector<int>re;
        int d=S.length();
        cout<<d;
        int in=0;
        for(int i=0;i<S.length();i++){ 
        if(S[i]=='I'){ 
            re.push_back(in);
            visited[in]=1;
            in++;
        
        }
            if(S[i]=='D'){ 
            re.push_back(d);
            visited[d]=1;
            d--;
        
        }
 
        }
        for(int j=0;j<S.length();j++)
        {
            if(visited[j]==0){ 
            re.push_back(j);
                break;
            }
        }
        return re;
    }
};