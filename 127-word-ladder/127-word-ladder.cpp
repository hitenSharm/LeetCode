class Solution {
public:


    int ladderLength(string b, string e, vector<string>& wordList) {
        unordered_map<string, vector<string>>adj;
        unordered_set<string>vis;
        queue<string>q;
        unordered_set<string>words;
        
        for(auto i:wordList)words.insert(i);
        if(words.find(b)==words.end())wordList.push_back(b);
        
        //finding 1 different word needs to be optimised
        
        for(auto s:wordList)
        {
            string og=s;
            for(int i=0;i<s.size();i++)
            {
                char actual=s[i];
                for(char j='a';j<='z';j++)
                {
                    s[i]=j;
                    // cout<<s<<endl;
                    if(words.find(s)!=words.end() and s!=og)
                    {
                        //cout<<og<<" "<<s<<"\n";
                        adj[og].push_back(s); //makes graph
                    }
                }
                s[i]=actual;
            }
        }
        
        q.push(b);
        int level=1;
        vis.insert(b);
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                string c=q.front();
                q.pop();
                if(c==e)return level;
                vector<string>& candi=adj[c];
                for(auto i:candi)
                {
                    if(vis.find(i)==vis.end())
                    {
                        vis.insert(i);
                        q.push(i);
                        if(i==e)return level+1;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};