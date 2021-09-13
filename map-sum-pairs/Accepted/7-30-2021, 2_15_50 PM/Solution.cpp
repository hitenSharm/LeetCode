// https://leetcode.com/problems/map-sum-pairs

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    bool match(string s,string& pre){
        int i=0;
        while(i<pre.length())
        {
            if(s[i]==pre[i])
            {
                i++;
                continue;
            }
            else
                return false;
        }
        return true;
    }
    
    unordered_map<string,int>ump;
    void insert(string key, int val) {
        ump[key]=val;
    }
    
    int sum(string prefix) {
        int ans=0;
        for(auto it:ump)
        {
            if(match(it.first,prefix))
                ans+=it.second;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */