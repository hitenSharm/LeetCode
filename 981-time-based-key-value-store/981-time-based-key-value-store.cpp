class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap(){
    }
    
    unordered_map<int,pair<string,string>>ump;
    
    void set(string key, string value, int timestamp) {
        ump[timestamp]=make_pair(key,value);    
    }
    
    string get(string key, int timestamp) {
        for(int i=timestamp;i>=1;i--)
        {
            if(ump.find(i)==ump.end())continue;  
            pair<string,string>&p=ump[i];
            if(p.first!=key)continue;
            return p.second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */