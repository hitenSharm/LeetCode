class LockingTree {
    vector<int>nodes;//parent array
    unordered_map<int,int>lockedNodes;//nodes, user
    unordered_map<int,vector<int>>children;
    public:
    LockingTree(vector<int>& parent) {
        nodes=parent;
        for(int i=0;i<parent.size();i++)
        {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(lockedNodes.find(num)!=lockedNodes.end())return false;
        
        lockedNodes[num]=user;//lock the node
        
        return true;
    }
    
    bool unlock(int num, int user) {
        if(lockedNodes.find(num)==lockedNodes.end())return false;//unlocked
        if(lockedNodes[num]!=user)return false;//wrong user unlocking the node
        
        lockedNodes.erase(num);//unlocking node
        return true;
    }
    
    bool ancestors(int curr)
    {
        while(curr!=-1)
        {
            if(lockedNodes.find(curr)!=lockedNodes.end())return false; //ancestor was locked
            curr=nodes[curr];
        }
        //all unlocked parents
        return true; 
    }
    
    bool desc(int curr)
    {
        int fl=0;//make 1 when i find a locked node
        queue<int>q;
        q.push(curr);
        while(!q.empty())
        {
            int c=q.front();q.pop();
            if(lockedNodes.find(c)!=lockedNodes.end()){
                fl=1;
                lockedNodes.erase(c);//unlock node
            }
            vector<int>& kids=children[c];
            for(int i=0;i<kids.size();i++)
            {
                q.push(kids[i]);
            }
        }
        if(fl==0)return false;//no locked nodes
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(lockedNodes.find(num)!=lockedNodes.end())return false;
        
        if(ancestors(num) and desc(num)){
            lockedNodes[num]=user;
            return true;
        }        
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */