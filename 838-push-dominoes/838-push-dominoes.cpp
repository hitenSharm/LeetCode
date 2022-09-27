class Solution {
public:
    string pushDominoes(string dom) {
        queue<int>q;
        for(int i=0;i<dom.size();i++)
        {
            if(dom[i]=='L' || dom[i]=='R')q.push(i);
        }
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                int curr=q.front();
                q.pop();
                int next=-1;
                if(!q.empty())next=q.front();
                //check special case of both doms
                if(next!=-1 and (dom[curr]=='R' and dom[next]=='L') and next==curr+2)
                {
                    len--;
                    q.pop();//pop twice as cant have these 2 
                    continue ;//do nothing
                }
                if(dom[curr]=='R' and curr+1<dom.size() and dom[curr+1]=='.')
                {
                    dom[curr+1]='R';
                    q.push(curr+1);
                }
                if(dom[curr]=='L' and curr-1>=0 and dom[curr-1]=='.')
                {
                    dom[curr-1]='L';
                    q.push(curr-1);
                }
            }
        }
        return dom;
    }
};