class TimeMap {
public:
    unordered_map<string,map<int,string>>ump;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
      auto it = ump[key].upper_bound(timestamp);
        if(it == ump[key].begin() )return "";
      it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */